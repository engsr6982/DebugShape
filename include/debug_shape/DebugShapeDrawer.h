#pragma once
#include "debug_shape/IDebugShape.h"
#include "debug_shape/Macro.h"
#include <vector>

#include "mc/_HeaderOutputPredefine.h"
#include "mc/network/packet/ServerScriptDebugDrawerPacket.h"

class Player;

namespace debug_shape {

using ShapeDrawerPacket = ScriptModuleDebugUtilities::ServerScriptDebugDrawerPacket;

class DebugShapeDrawer {
public:
    DebugShapeDrawer() = delete;

    DBG_SHAPE_API static void drawShape(IDebugShape const* shape, Player* player);
    DBG_SHAPE_API static void drawShape(IDebugShape const* shape, DimensionType dimension);
    DBG_SHAPE_API static void drawShapes(std::vector<IDebugShape const*> const& shapes, Player* player);
    DBG_SHAPE_API static void drawShapes(std::vector<IDebugShape const*> const& shapes, DimensionType dimension);

    DBG_SHAPE_API static void removeShape(IDebugShape const* shape, Player* player);
    DBG_SHAPE_API static void removeShape(IDebugShape const* shape, DimensionType dimension);
    DBG_SHAPE_API static void removeShapes(std::vector<IDebugShape const*> const& shapes, Player* player);
    DBG_SHAPE_API static void removeShapes(std::vector<IDebugShape const*> const& shapes, DimensionType dimension);
};


} // namespace debug_shape