#ifndef XGPU_CORE_EXPECTED_HPP_
#define XGPU_CORE_EXPECTED_HPP_

#include "error.hpp"

#include <rtl/expected.h>

namespace xgpu
{
    template <typename T>
    using expected = rtl::expected<T, core::Error>;
} // namespace xgpu

#endif // XGPU_CORE_EXPECTED_HPP_