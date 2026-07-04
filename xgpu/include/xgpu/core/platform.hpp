#ifndef XGPU_CORE_PLATFORM_HPP_
#define XGPU_CORE_PLATFORM_HPP_

#include "enum_wrapper.hpp"
#include "platform_detection.hpp"

namespace xgpu::core
{
    /// @brief Enumeration of supported platforms
    enum class Platform
    {
        MacOS,
        Linux,
        Windows,
    };

    template <>
    inline constexpr std::string
    utils::EnumWrapper<Platform>::to_string() const noexcept
    {
        switch ( value() ) {
        case Platform::MacOS:
            return "MacOS";
        case Platform::Linux:
            return "Linux";
        case Platform::Windows:
            return "Windows";
        }

        return "UnknownPlatform";
    }

    template <Platform P>
    consteval bool
    platform_available()
    {
        return false;
    }

    template <>
    consteval bool
    platform_available<Platform::MacOS>()
    {
#ifdef XGPU_PLATFORM_MACOS
        return true;
#endif // XGPU_PLATFORM_MACOS
        return false;
    }

    template <>
    consteval bool
    platform_available<Platform::Linux>()
    {
        return false;
    }

    template <>
    consteval bool
    platform_available<Platform::Windows>()
    {
        return false;
    }

    consteval utils::EnumWrapper<Platform>
    current_platform()
    {
        if constexpr ( platform_available<Platform::MacOS>() ) {
            return utils::EnumWrapper(Platform::MacOS);
        }

        if constexpr ( platform_available<Platform::Windows>() ) {
            return utils::EnumWrapper(Platform::Windows);
        }

        if constexpr ( platform_available<Platform::Linux>() ) {
            return utils::EnumWrapper(Platform::Linux);
        }

        // TODO: properly handle this
        return utils::EnumWrapper(Platform::Linux);
    }
} // namespace xgpu::core

#endif // XGPU_CORE_PLATFORM_HPP_