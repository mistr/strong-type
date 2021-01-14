#ifndef COLLECT_HH_DB340D308829C098EDBC78EA1D3BBE09//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define COLLECT_HH_DB340D308829C098EDBC78EA1D3BBE09

#include <type_traits>

namespace LibStrong {

template <template <typename> class ...SubSkills>
struct Collect
{
    template <typename Derived>
    struct Skill : SubSkills<Derived>...
    { };
};

}//namespace LibStrong

#endif//COLLECT_HH_DB340D308829C098EDBC78EA1D3BBE09
