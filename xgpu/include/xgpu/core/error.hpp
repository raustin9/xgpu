#ifndef XGPU_CORE_ERROR_H_
#define XGPU_CORE_ERROR_H_

#include "enum_wrapper.hpp"

#include <cstdint>

namespace xgpu::core
{
    /// @brief Enumeration of varying serverities/levels of an error
    enum class ErrorLevel : std::uint32_t
    {
        Warning = 0,
        Error = 1,
        Fatal = 2
    };

    template <>
    inline constexpr std::string
    utils::EnumWrapper<ErrorLevel>::to_string() const noexcept
    {
        switch ( value() )
        {
            case ErrorLevel::Warning:
                return "WARNING";
            case ErrorLevel::Error:
                return "ERROR";
            case ErrorLevel::Fatal:
                return "FATAL";
            default:
                return "UNKNOWN_ERROR_LEVEL";
        }
    }
} // namespace xgpu::core

#endif // XGPU_CORE_ERROR_H_