#include "libstrong/type.hh"

namespace LibStrong {
namespace {

using Id = SerialId<int, struct IdTag_>;

static_assert(*Id{1} == 1, "must be '1'");

static_assert(Id{1} < Id{2}, "'1' must be lesser than '2'");
static_assert(!(Id{1} < Id{1}), "'1' can not be lesser than '1'");
static_assert(!(Id{2} < Id{1}), "'2' can not be lesser than '1'");
static_assert(Id{1} <= Id{2}, "'1' must be lesser than or equal to '2'");
static_assert(Id{1} <= Id{1}, "'1' must be lesser than or equal to '1'");
static_assert(!(Id{2} <= Id{1}), "'2' can not be lesser than nor equal to '1'");
static_assert(!(Id{1} == Id{2}), "'1' can not be equal to '2'");
static_assert(Id{1} == Id{1}, "'1' must be equal to '1'");
static_assert(!(Id{2} == Id{1}), "'2' can not be equal to '1'");
static_assert(Id{1} != Id{2}, "'1' must differ from '2'");
static_assert(!(Id{1} != Id{1}), "'1' can not differ from '1'");
static_assert(Id{2} != Id{1}, "'2' must differ from '1'");
static_assert(!(Id{1} >= Id{2}), "'1' can not be greater than nor equal to '2'");
static_assert(Id{1} >= Id{1}, "'1' must be greater than or equal to '1'");
static_assert(Id{2} >= Id{1}, "'2' must be greater than or equal to '1'");
static_assert(!(Id{1} > Id{2}), "'1' can not be greater than '2'");
static_assert(!(Id{1} > Id{1}), "'1' can not be greater than '1'");
static_assert(Id{2} > Id{1}, "'2' must be greater than '1'");

static_assert(Id{1} + 2 == Id{3}, "sum must be '3'");
static_assert(Id{3} - 2 == Id{1}, "diff must be '1'");
static_assert(Id{3} - Id{2} == 1, "diff must be '1'");

}//namespace LibStrong::{anonymous}
}//namespace LibStrong
