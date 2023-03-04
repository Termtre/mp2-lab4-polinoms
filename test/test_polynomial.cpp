#include <gtest.h>
#include "polynomial.h"

TEST(Polynomial, can_create_tpostfix_without_infix)
{
    Monom a(0, 2.5);
    Monom c;
    c = a + 2;
    ASSERT_NO_THROW();
}