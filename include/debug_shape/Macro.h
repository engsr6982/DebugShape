#pragma once

#ifndef DEBUG_SHAPE_EXPORT
#define DBG_SHAPE_API __declspec(dllexport)
#else
#define DBG_SHAPE_API __declspec(dllimport)
#endif

#define DBG_SHAPE_ND_API [[nodiscard]] DBG_SHAPE_API