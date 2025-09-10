#pragma once
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
    IDebugShape();
    virtual ~IDebugShape();

    IDebugShape(const IDebugShape&)            = delete;
    IDebugShape& operator=(const IDebugShape&) = delete;

    virtual void draw() const;                        // sendToClients
    virtual void draw(Player& player) const;          // sendToPlayer
    virtual void draw(DimensionType dimension) const; // sendToDimension
    virtual void update() const;
    virtual void update(Player& player) const;
    virtual void update(DimensionType dimension) const;
    virtual void remove() const;
    virtual void remove(Player& player) const;
    virtual void remove(DimensionType dimension) const;
};


} // namespace debug_shape