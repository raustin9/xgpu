#ifndef XGPU_DATA_PHYSICAL_DEVICE_HPP_
#define XGPU_DATA_PHYSICAL_DEVICE_HPP_

#include "core/core.hpp"
#include "physical_device_type.hpp"

#include <cstdint>

namespace xgpu::data
{
    /// @brief Contains information portaining to a physical device
    struct PhysicalDevice 
    {
        /// @brief The name of the physical device
        std::string name = "";

        /// @brief The kind of physical device
        PhysicalDeviceType kind = PhysicalDeviceTypeVariant::Unknown;

        /// @brief The capabilities that a physical device may include
        struct Capabilities
        {
            /// @brief true if compute is supported
            bool compute = false;

            /// @brief true if graphics is supported
            bool graphics = false;
        } capabilities {};

        [[nodiscard]] constexpr bool
        operator==(const PhysicalDevice &rhs) const noexcept
        {
            return name == rhs.name && type == rhs.type && video_ram_bytes == rhs.video_ram_bytes
                   && capabilities.compute == rhs.capabilities.compute
                   && capabilities.graphics == rhs.capabilities.graphics;
        }
    };
} // namespace xgpu::data

#endif // XGPU_DATA_PHYSICAL_DEVICE_HPP_