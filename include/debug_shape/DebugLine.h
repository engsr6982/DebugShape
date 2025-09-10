#pragma once
#include "debug_shape/DebugShape.h"


namespace debug_shape {

/**
 * 调试线段
 * @see
 * https://learn.microsoft.com/en-us/minecraft/creator/scriptapi/minecraft/debug-utilities/debugline?view=minecraft-bedrock-experimental
 */
class DebugLine : public DebugShape {
public:
    DBG_SHAPE_API explicit DebugLine(Vec3 const& start, Vec3 const& end);

    DBG_SHAPE_ND_API std::optional<Vec3> getEndPosition() const;

    DBG_SHAPE_API void setEndPosition(std::optional<Vec3> loc);
};

} // namespace debug_shape