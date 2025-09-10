#pragma once
#include "debug_shape/DebugShape.h"


namespace debug_shape {

/**
 * 调试球
 * @see
 * https://learn.microsoft.com/en-us/minecraft/creator/scriptapi/minecraft/debug-utilities/debugsphere?view=minecraft-bedrock-experimental
 */
class DebugSphere : public DebugShape {
public:
    DBG_SHAPE_API explicit DebugSphere(Vec3 const& loc);
};

} // namespace debug_shape