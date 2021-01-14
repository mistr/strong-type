#ifndef OPTIONAL_HH_3F70C1817FC8780B5D064C5D8F4894C1//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define OPTIONAL_HH_3F70C1817FC8780B5D064C5D8F4894C1

#include "libstrong/type.hh"

#include <boost/optional.hpp>

#include <utility>

namespace LibStrong {

template <typename T, typename Tag, template <typename> class Skills>
class Type<T, Tag, Skills>::Optional : public boost::optional<Type>
{
public:
    using UnderlyingStrongType = Type<T, Tag, Skills>;
    using UnderlyingOptionalType = boost::optional<UnderlyingStrongType>;
    Optional() = delete;
    constexpr Optional(UnderlyingStrongType src) noexcept(std::is_nothrow_constructible<UnderlyingOptionalType,
                                                                                        std::add_rvalue_reference_t<UnderlyingStrongType>>::value)
        : UnderlyingOptionalType{std::move(src)}
    { }
    Optional(NullOpt) noexcept(std::is_nothrow_constructible<UnderlyingOptionalType, boost::none_t>::value)
        : UnderlyingOptionalType{boost::none}
    { }
    explicit Optional(boost::none_t) noexcept(std::is_nothrow_constructible<Optional, NullOpt>::value)
        : Optional{nullopt}
    { }

    bool operator==(NullOpt) const
    {
        return *this == boost::none;
    }
    bool operator!=(NullOpt) const
    {
        return *this != boost::none;
    }

    Optional& operator=(NullOpt) noexcept(std::is_nothrow_assignable<UnderlyingOptionalType, boost::none_t>::value)
    {
        return *this = boost::none;
    }
};

}//namespace LibStrong

#endif//OPTIONAL_HH_3F70C1817FC8780B5D064C5D8F4894C1
