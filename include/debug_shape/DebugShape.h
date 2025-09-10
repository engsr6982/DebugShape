#pragma once
#include "debug_shape/Macro.h"
#include "mc/deps/core/math/Color.h"
#include "mc/deps/core/math/Vec3.h"
#include "mc/network/packet/PacketShapeData.h"
#include "mc/network/packet/ServerScriptDebugDrawerPacket.h"
#include "mc/scripting/modules/minecraft/debugdrawer/ScriptDebugShapeType.h"
#include <optional>


namespace debug_shape {

using DebugShapeType    = ScriptModuleDebugUtilities::ScriptDebugShapeType;
using ShapePacketData   = ScriptModuleDebugUtilities::PacketShapeData;
using ShapeDrawerPacket = ScriptModuleDebugUtilities::ServerScriptDebugDrawerPacket;

/**
 * 调试形状
 * @see
 * https://learn.microsoft.com/en-us/minecraft/creator/scriptapi/minecraft/debug-utilities/debugshape?view=minecraft-bedrock-experimental
 */
class DebugShape {
protected:
    ShapePacketData mPacketData{};

private:
    std::unique_ptr<ShapeDrawerPacket>        _buildPacket() const;
    static std::unique_ptr<ShapeDrawerPacket> _buildEmptyPacket();

    static inline uint64_t getNextId();

public:
    DBG_SHAPE_API explicit DebugShape(DebugShapeType type, Vec3 const& loc);
    virtual ~DebugShape();

    DBG_SHAPE_ND_API uint64_t getId() const; // 唯一id

    DBG_SHAPE_ND_API DebugShapeType getType() const; // 形状类型

    DBG_SHAPE_ND_API std::optional<Vec3> getPosition() const; // 位置

    DBG_SHAPE_API void setPosition(Vec3 const& loc);

    DBG_SHAPE_ND_API std::optional<Vec3> getRotation() const; // 旋转

    DBG_SHAPE_API void setRotation(std::optional<Vec3> rot);

    DBG_SHAPE_ND_API std::optional<float> getScale() const; // 缩放

    DBG_SHAPE_API void setScale(std::optional<float> s);

    DBG_SHAPE_ND_API std::optional<mce::Color> getColor() const; // 颜色

    DBG_SHAPE_API void setColor(std::optional<mce::Color> c);

    DBG_SHAPE_ND_API bool hasDuration() const; // 是否有持续时间

    DBG_SHAPE_ND_API std::optional<float> getTotalTimeLeft() const; // 剩余时间

    DBG_SHAPE_API void setTotalTimeLeft(std::optional<float> t);

    DBG_SHAPE_API virtual void draw(int dimensionId) const;
    DBG_SHAPE_API virtual void draw(Player& player) const;

    DBG_SHAPE_API virtual void remove() const;
    DBG_SHAPE_API virtual void remove(Player& player) const;
};


} // namespace debug_shape
