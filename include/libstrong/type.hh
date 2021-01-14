#ifndef TYPE_HH_9460A490234B8DE81D50B83C77C69920//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define TYPE_HH_9460A490234B8DE81D50B83C77C69920

#include "libstrong/collect.hh"

#include "libstrong/skill/comparable.hh"
#include "libstrong/skill/serial_id.hh"
#include "libstrong/skill/streamable.hh"

#include <string>
#include <type_traits>
#include <utility>

namespace LibStrong {

template <typename T, typename Tag, template <typename> class Skills>
class Type : public Skills<Type<T, Tag, Skills>>
{
public:
    static_assert(!std::is_reference<T>::value, "T can not be reference");
    using UnderlyingType = T;
    using UnderlyingTypeRef = std::add_lvalue_reference_t<UnderlyingType>;
    using UnderlyingTypeCRef = std::add_lvalue_reference_t<std::add_const_t<UnderlyingType>>;
    using UnderlyingTypePtr = std::add_pointer_t<UnderlyingType>;
    using UnderlyingTypeCPtr = std::add_pointer_t<std::add_const_t<UnderlyingType>>;

    template <typename _T = UnderlyingType, std::enable_if_t<std::is_default_constructible<_T>::value>* = nullptr>
    constexpr Type() noexcept(std::is_nothrow_default_constructible<_T>::value)
        : value_{}
    { }
    template <typename _T = UnderlyingType, std::enable_if_t<std::is_copy_constructible<_T>::value>* = nullptr>
    explicit constexpr Type(const UnderlyingType& src) noexcept(std::is_nothrow_copy_constructible<_T>::value)
        : value_{src}
    { }
    template <typename _T = UnderlyingType, std::enable_if_t<std::is_move_constructible<_T>::value>* = nullptr>
    explicit constexpr Type(UnderlyingType&& src) noexcept(std::is_nothrow_move_constructible<_T>::value)
        : value_{std::move(src)}
    { }
    template <typename _T = UnderlyingType, std::enable_if_t<std::is_copy_constructible<_T>::value>* = nullptr>
    constexpr Type(const Type& src) noexcept(std::is_nothrow_copy_constructible<_T>::value)
        : value_{*src}
    { }
    template <typename _T = UnderlyingType, std::enable_if_t<std::is_move_constructible<_T>::value>* = nullptr>
    constexpr Type(Type&& src) noexcept(std::is_nothrow_move_constructible<UnderlyingType>::value)
        : value_{*std::move(src)}
    { }
    constexpr UnderlyingTypeCRef operator*() const& noexcept
    {
        return value_;
    }
    constexpr UnderlyingTypeRef operator*() & noexcept
    {
        return value_;
    }
    constexpr std::enable_if_t<std::is_move_constructible<T>::value, UnderlyingType> operator*() && noexcept(std::is_nothrow_move_constructible<T>::value)
    {
        return std::move(value_);
    }
    constexpr UnderlyingTypeCPtr operator->() const& noexcept
    {
        return &value_;
    }
    constexpr UnderlyingTypePtr operator->() & noexcept
    {
        return &value_;
    }
    struct NullOpt
    {
        constexpr explicit NullOpt(int) { }
    };
    static constexpr auto nullopt = NullOpt{0};
    class Optional;
private:
    UnderlyingType value_;
};

template <typename T, typename Tag>
using SerialId = Type<T, Tag, Skill::SerialId>;

template <typename T, typename Tag>
using RandomId = Type<T, Tag, Collect<Skill::Comparable, Skill::Streamable>::Skill>;

template <typename Tag>
using StringId = RandomId<std::string, Tag>;

}//namespace LibStrong

#include "libstrong/optional.hh"

#endif//TYPE_HH_9460A490234B8DE81D50B83C77C69920
