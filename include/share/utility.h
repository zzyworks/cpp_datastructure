#ifndef UTILITY_H
#define UTILITY_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <typeinfo>

#include "comparator.hpp"

#include "check_order_elem.hpp"
#include "check_order_list.hpp"
#include "check_order_vector.hpp"

#include "double_elem.hpp"
#include "hailstone_elem.hpp"

#include "increase_elem.hpp"
#include "increase_list.hpp"
#include "increase_vector.hpp"

#include "decrease_elem.hpp"
#include "decrease_list.hpp"
#include "decrease_vector.hpp"

#include "crc_elem.hpp"
#include "crc_list.hpp"
#include "crc_vector.hpp"

#include "rand.hpp" //随机数

#include "type_traits.hpp"

using Rank = int;

#if defined(DSA_DEBUG) //编译开关，控制调试输出
#define DSA(x)  { x } //输出
#else
#define DSA(x) //不输出
#endif

#endif  // UTILITY_H