#include "debug_shape/IDebugShape.h"
#include "debug_shape/DebugShapeDrawer.h"
#include "debug_shape/internal/GlobalIDAllocator.h"

#include "mc/_HeaderOutputPredefine.h"
#include "mc/world/level/dimension/Dimension.h"

namespace debug_shape {

IDebugShape::IDebugShape() { mShapeData.mNetworkId = internal::GlobalIDAllocator::allocateID(); }

IDebugShape::~IDebugShape() { remove(); }

void IDebugShape::draw() const { DebugShapeDrawer::drawShape(this, nullptr); }
void IDebugShape::draw(Player& player) const { DebugShapeDrawer::drawShape(this, &player); }
void IDebugShape::draw(DimensionType dimension) const { DebugShapeDrawer::drawShape(this, dimension); }

void IDebugShape::update() const {
    remove();
    draw();
}
void IDebugShape::update(Player& player) const {
    remove(player);
    draw(player);
}
void IDebugShape::update(DimensionType dimension) const {
    remove(dimension);
    draw(dimension);
}

void IDebugShape::remove() const { DebugShapeDrawer::removeShape(this, nullptr); }
void IDebugShape::remove(Player& player) const { DebugShapeDrawer::removeShape(this, &player); }
void IDebugShape::remove(DimensionType dimension) const { DebugShapeDrawer::removeShape(this, dimension); }

} // namespace debug_shape