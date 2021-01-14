#ifndef COMPARABLE_HH_A2F59A0082D0BD1D9CCF17FC636AA259//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define COMPARABLE_HH_A2F59A0082D0BD1D9CCF17FC636AA259

namespace LibStrong {
namespace Skill {

template <typename Derived>
struct Comparable
{
    friend constexpr bool operator<(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs < *rhs;
    }
    friend constexpr bool operator<=(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs <= *rhs;
    }
    friend constexpr bool operator==(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs == *rhs;
    }
    friend constexpr bool operator!=(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs != *rhs;
    }
    friend constexpr bool operator>=(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs >= *rhs;
    }
    friend constexpr bool operator>(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs > *rhs;
    }
};

}//namespace LibStrong::Skill
}//namespace LibStrong

#endif//COMPARABLE_HH_A2F59A0082D0BD1D9CCF17FC636AA259
