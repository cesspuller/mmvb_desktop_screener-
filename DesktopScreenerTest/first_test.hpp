//! Проверочный тест
#ifndef _FIRST_TEST_H_
#define _FIRST_TEST_H_

#include "../packages/Microsoft.googletest.v140.windesktop.msvcstl.dyn.rt-dyn.1.8.1.4/build/native/include/gtest/gtest.h"

TEST( IntegerTest, Addition )
{
   EXPECT_EQ( 4, 2 + 2 );
   EXPECT_EQ( 10, 3 + 7 );
};
#endif /* _FIRST_TEST_H_ */
