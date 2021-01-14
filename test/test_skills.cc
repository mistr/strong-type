#include "libstrong/type.hh"

#include <boost/test/unit_test.hpp>

#include <sstream>
#include <string>

BOOST_AUTO_TEST_SUITE(TestSkills)

namespace {

using Id = LibStrong::SerialId<int, struct IdTag_>;

using FirstName = LibStrong::StringId<struct FirstNameTag_>;
using MiddleName = LibStrong::StringId<struct MiddleNameTag_>;
using LastName = LibStrong::StringId<struct LastNameTag_>;
using FullName = LibStrong::StringId<struct FullNameTag_>;

FullName compose(const FirstName& first_name, const MiddleName::Optional& middle_name, const LastName& last_name)
{
    BOOST_CHECK_EQUAL(middle_name == boost::none, middle_name == MiddleName::nullopt);
    return FullName{middle_name == boost::none ? *first_name + " " + *last_name
                                               : *first_name + " " + **middle_name + " " + *last_name};
}

}//namespace {anonymous}

BOOST_AUTO_TEST_CASE(test_output)
{
    std::ostringstream out;
    out << Id{1};
    BOOST_CHECK_EQUAL(out.str(), "1");
}

BOOST_AUTO_TEST_CASE(test_increment)
{
    auto id = Id{1};
    BOOST_CHECK_EQUAL(id, Id{1});
    BOOST_CHECK_EQUAL(++id, Id{2});
    BOOST_CHECK_EQUAL(id++, Id{2});
    BOOST_CHECK_EQUAL(id, Id{3});
    BOOST_CHECK_EQUAL(id += 2, Id{5});
}

BOOST_AUTO_TEST_CASE(test_decrement)
{
    auto id = Id{3};
    BOOST_CHECK_EQUAL(id, Id{3});
    BOOST_CHECK_EQUAL(--id, Id{2});
    BOOST_CHECK_EQUAL(id--, Id{2});
    BOOST_CHECK_EQUAL(id, Id{1});
    BOOST_CHECK_EQUAL(id -= 2, Id{-1});
}

BOOST_AUTO_TEST_CASE(test_string_id)
{
    BOOST_CHECK_EQUAL(compose(FirstName{"Karel"}, MiddleName{"von"}, LastName{"Bahnhof"}), FullName{"Karel von Bahnhof"});
    BOOST_CHECK_EQUAL(compose(FirstName{"Karel"}, MiddleName::nullopt, LastName{"Bahnhof"}), FullName{"Karel Bahnhof"});
}

BOOST_AUTO_TEST_SUITE_END()//TestSkills
