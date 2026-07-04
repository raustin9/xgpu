#ifndef XGPU_DATA_PHYSICAL_DEVICE_TYPE_HPP_
#define XGPU_DATA_PHYSICAL_DEVICE_TYPE_HPP_

#include "core/core.hpp"

#include <cstdint>

namespace xgpu::data
{
    enum class PhysicalDeviceTypeVariant : std::uint32_t
    {
        DiscreteGPU,
        IntegratedGPU,
        Unknown
    };

    using PhysicalDeviceType = core::utils::EnumWrapper<PhysicalDeviceTypeVariant>;

    template <>
    inline constexpr std::string
    PhysicalDeviceType::to_string() const noexcept
    {
        switch ( value() )
        {
            case PhysicalDeviceType::DiscreteGPU:
                return "DiscreteGPU";
            case PhysicalDeviceType::IntegratedGPU:
                return "IntegratedGPU";
            case PhysicalDeviceType::Unknown:
            default:
                return "Unknown";
        }
    }
} // namespace xgpu::data

#endif // XGPU_DATA_PHYSICAL_DEVICE_TYPE_HPP_