#pragma once
#include "debug_shape/DebugLine.h"

namespace debug_shape {

/**
 * 调试箭头
 * @see
 * https://learn.microsoft.com/en-us/minecraft/creator/scriptapi/minecraft/debug-utilities/debugarrow?view=minecraft-bedrock-experimental
 */
class DebugArrow : public DebugLine {
public:
    DBG_SHAPE_API explicit DebugArrow(Vec3 const& start, Vec3 const& end);

    DBG_SHAPE_ND_API std::optional<float> getHeadLength() const; // 箭头长度

    DBG_SHAPE_API void setHeadLength(std::optional<float> l);

    DBG_SHAPE_ND_API std::optional<float> getHeadRadius() const; // 箭头半径

    DBG_SHAPE_API void setHeadRadius(std::optional<float> r);

    DBG_SHAPE_ND_API std::optional<uint8_t> getHeadSegments() const; // 箭头分段数

    DBG_SHAPE_API void setHeadSegments(std::optional<uint8_t> s);
};

} // namespace debug_shape