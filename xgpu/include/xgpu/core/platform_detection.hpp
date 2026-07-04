#ifndef XGPU_CORE_PLATFORM_DETECTION_HPP_
#define XGPU_CORE_PLATFORM_DETECTION_HPP_

#if defined(__APPLE__)
#define XGPU_APPLE
#include <TargetConditionals.h>

#if TARGET_OS_IPHONE
#define XGPU_PLATFORM_IOS
#elif defined(TARGET_OS_MAC)
#define XGPU_PLATFORM_MACOS
#endif

#elif defined(WIN32) || defined(__WIN32) || defined(__WIN32__)
#define XGPU_PLATFORM_WIN32
#endif

#endif // XGPU_CORE_PLATFORM_DETECTION_HPP_