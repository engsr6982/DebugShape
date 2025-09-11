#pragma once
#include "debug_shape/Macro.h"

#include "mc/_HeaderOutputPredefine.h"
#include "mc/network/packet/PacketShapeData.h"
#include "mc/scripting/modules/minecraft/debugdrawer/ScriptDebugShapeType.h"

class Player;

namespace debug_shape {

using DebugShapeType  = ScriptModuleDebugUtilities::ScriptDebugShapeType;
using ShapeDataPacket = ScriptModuleDebugUtilities::PacketShapeData;

using ShapeID = uint64_t;

inline constexpr ShapeID InvalidShapeID = 0;

class IDebugShape {
protected:
    ShapeDataPacket mShapeData;

    friend class DebugShapeDrawer;

public:
    DSAPI IDebugShape();
    DSAPI virtual ~IDebugShape();

    IDebugShape(const IDebugShape&)            = delete;
    IDebugShape& operator=(const IDebugShape&) = delete;

    DSAPI virtual void draw() const;                        // sendToClients
    DSAPI virtual void draw(Player& player) const;          // sendToPlayer
    DSAPI virtual void draw(DimensionType dimension) const; // sendToDimension
    DSAPI virtual void update() const;
    DSAPI virtual void update(Player& player) const;
    DSAPI virtual void update(DimensionType dimension) const;
    DSAPI virtual void remove() const;
    DSAPI virtual void remove(Player& player) const;
    DSAPI virtual void remove(DimensionType dimension) const;
};


} // namespace debug_shape