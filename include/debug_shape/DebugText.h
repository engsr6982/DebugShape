#pragma once
#include "debug_shape/DebugShape.h"


namespace debug_shape {

/**
 * 调试文本
 * @see
 * https://learn.microsoft.com/en-us/minecraft/creator/scriptapi/minecraft/debug-utilities/debugtext?view=minecraft-bedrock-experimental
 */
class DebugText : public DebugShape {
public:
    DBG_SHAPE_API explicit DebugText(Vec3 const& loc, const std::string& text);

    DBG_SHAPE_ND_API std::optional<std::string> getText() const;

    DBG_SHAPE_API void setText(const std::string& txt);
};

} // namespace debug_shape