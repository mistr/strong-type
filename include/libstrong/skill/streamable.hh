#ifndef STREAMABLE_HH_359ABBCD4023E6F47A86ADA8C33B376B//date "+%s.%N"|md5sum|tr "[a-f]" "[A-F]"
#define STREAMABLE_HH_359ABBCD4023E6F47A86ADA8C33B376B

#include <iostream>

namespace LibStrong {
namespace Skill {

template <typename Derived>
struct Streamable
{
    friend std::ostream& operator<<(std::ostream& out, const Derived& value)
    {
        return out << *value;
    }
};

}//namespace LibStrong::Skill
}//namespace LibStrong

#endif//STREAMABLE_HH_359ABBCD4023E6F47A86ADA8C33B376B
