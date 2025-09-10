#include "debug_shape/DebugShapeDrawer.h"
#include "debug_shape/IDebugShape.h"

#include "mc/_HeaderOutputPredefine.h"
#include "mc/world/level/BlockPos.h"
#include "mc/world/level/BlockSourceListener.h"
#include "mc/world/level/dimension/Dimension.h"

namespace debug_shape {


void DebugShapeDrawer::drawShape(IDebugShape const* shape, Player* player) { drawShapes({shape}, player); }
void DebugShapeDrawer::drawShape(IDebugShape const* shape, DimensionType dimension) { drawShapes({shape}, dimension); }
void DebugShapeDrawer::drawShapes(std::vector<IDebugShape const*> const& shapes, Player* player) {
    if (shapes.empty()) return;
    ShapeDrawerPacket packet;
    for (auto shape : shapes) {
        packet.mShapes->push_back(shape->mShapeData);
    }
    if (player) {
        packet.sendTo(*player);
    } else {
        packet.sendToClients();
    }
}
void DebugShapeDrawer::drawShapes(std::vector<IDebugShape const*> const& shapes, DimensionType dimension) {
    if (shapes.empty()) return;
    ShapeDrawerPacket packet;
    for (auto shape : shapes) {
        packet.mShapes->push_back(shape->mShapeData);
    }
    auto loc = shapes[0]->mShapeData.mLocation->value_or(BlockPos{});
    packet.sendTo(loc, dimension);
}

void DebugShapeDrawer::removeShape(IDebugShape const* shape, Player* player) { removeShapes({shape}, player); }
void DebugShapeDrawer::removeShape(IDebugShape const* shape, DimensionType dimension) {
    removeShapes({shape}, dimension);
}
void DebugShapeDrawer::removeShapes(std::vector<IDebugShape const*> const& shapes, Player* player) {
    if (shapes.empty()) return;
    ShapeDrawerPacket packet;
    for (auto shape : shapes) {
        ShapeDataPacket data{};
        data.mNetworkId = shape->mShapeData.mNetworkId;
        packet.mShapes->push_back(std::move(data));
    }
    if (player) {
        packet.sendTo(*player);
    } else {
        packet.sendToClients();
    }
}
void DebugShapeDrawer::removeShapes(std::vector<IDebugShape const*> const& shapes, DimensionType dimension) {
    if (shapes.empty()) return;
    ShapeDrawerPacket packet;
    for (auto shape : shapes) {
        ShapeDataPacket data{};
        data.mNetworkId = shape->mShapeData.mNetworkId;
    }
    auto loc = shapes[0]->mShapeData.mLocation->value_or(BlockPos{});
    packet.sendTo(loc, dimension);
}


} // namespace debug_shape