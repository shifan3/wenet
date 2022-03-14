// Copyright (c) 2021 Mobvoi Inc (Binbin Zhang)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef UTILS_LOG_H_
#define UTILS_LOG_H_

// Because openfst is a dynamic library compiled with gflags/glog, we must use
// the gflags/glog from openfst to avoid them linked both statically and
// dynamically into the executable.
#include "fst/log.h"


class check_error : public std::runtime_error
// BOOST_SYMBOL_VISIBLE is needed by GCC to ensure system_error thrown from a shared
// library can be caught. See svn.boost.org/trac/boost/ticket/3697
{
public:
    explicit check_error( const char* message )
        : std::runtime_error(message) {}


    virtual ~check_error() {}

private:
};

#define CHECK_OP_THROW(var1, var2, OP) OP(var1, var2); \
    throw check_error("check fail: " #var1 " " #OP " " #var2)

#define CHECK_THROW(cond) CHECK(cond); \
    throw check_error("check fail: " #cond);


#define CHECK_EQ_THROW(var1, var2) CHECK_OP_THROW(var1, var2, CHECK_EQ)
#define CHECK_NE_THROW(val1, val2) CHECK_OP_THROW(var1, var2, CHECK_NE)
#define CHECK_LE_THROW(val1, val2) CHECK_OP_THROW(var1, var2, CHECK_LE)
#define CHECK_LT_THROW(val1, val2) CHECK_OP_THROW(var1, var2, CHECK_LT)
#define CHECK_GE_THROW(val1, val2) CHECK_OP_THROW(var1, var2, CHECK_GE)
#define CHECK_GT_THROW(val1, val2) CHECK_OP_THROW(var1, var2, CHECK_GT)


#endif  // UTILS_LOG_H_
