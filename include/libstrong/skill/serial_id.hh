#ifndef SERIAL_ID_HH_947C330D84CD8E902561DCB5BB5CBD74//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define SERIAL_ID_HH_947C330D84CD8E902561DCB5BB5CBD74

#include "libstrong/skill/comparable.hh"
#include "libstrong/skill/streamable.hh"

#include <type_traits>
#include <utility>

namespace LibStrong {
namespace Skill {

template <typename Derived>
struct SerialId : Comparable<Derived>, Streamable<Derived>
{
    Derived& operator++() noexcept;
    Derived operator++(int) noexcept;
    Derived& operator--() noexcept;
    Derived operator--(int) noexcept;

    template <typename T>
    Derived& operator+=(T&& rhs) noexcept;
    template <typename T>
    Derived& operator-=(T&& rhs) noexcept;

    template <typename T>
    friend constexpr std::enable_if_t<!std::is_same<std::decay_t<T>, Derived>::value, Derived> operator+(const Derived& lhs, T&& rhs) noexcept
    {
        return Derived{*lhs + std::forward<T>(rhs)};
    }
    template <typename T>
    friend constexpr std::enable_if_t<!std::is_same<std::decay_t<T>, Derived>::value, Derived> operator-(const Derived& lhs, T&& rhs) noexcept
    {
        return Derived{*lhs - std::forward<T>(rhs)};
    }

    friend constexpr auto operator-(const Derived& lhs, const Derived& rhs) noexcept
    {
        return *lhs - *rhs;
    }
};

template <typename Derived>
Derived& SerialId<Derived>::operator++() noexcept
{
    ++(*static_cast<Derived&>(*this));
    return static_cast<Derived&>(*this);
}

template <typename Derived>
Derived SerialId<Derived>::operator++(int) noexcept
{
    return Derived{(*static_cast<Derived&>(*this))++};
}

template <typename Derived>
Derived& SerialId<Derived>::operator--() noexcept
{
    --(*static_cast<Derived&>(*this));
    return static_cast<Derived&>(*this);
}

template <typename Derived>
Derived SerialId<Derived>::operator--(int) noexcept
{
    return Derived{(*static_cast<Derived&>(*this))--};
}

template <typename Derived>
template <typename T>
Derived& SerialId<Derived>::operator+=(T&& rhs) noexcept
{
    (*static_cast<Derived&>(*this)) += std::forward<T>(rhs);
    return static_cast<Derived&>(*this);
}

template <typename Derived>
template <typename T>
Derived& SerialId<Derived>::operator-=(T&& rhs) noexcept
{
    (*static_cast<Derived&>(*this)) -= std::forward<T>(rhs);
    return static_cast<Derived&>(*this);
}

}//namespace LibStrong::Skill
}//namespace LibStrong

#endif//SERIAL_ID_HH_947C330D84CD8E902561DCB5BB5CBD74
