#include <gtest.h>
#include "polynomial.h"

TEST(Polynomial, can_create_empty_polynomial)
{
    ASSERT_NO_THROW(Polynomial A);
}

TEST(Polynomial, can_create_polynomial_with_help_of_monom_list)
{
    Monom a(2, 2.5);
    List<Monom> list(a);
    ASSERT_NO_THROW(Polynomial A(list));
}

TEST(Polynomial, can_create_polynomial_with_help_of_monom)
{
    Monom a(2, 2.5);
    ASSERT_NO_THROW(Polynomial A(a));
}

TEST(Polynomial, can_copy_polynomial)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    ASSERT_NO_THROW(Polynomial B(A));
}

TEST(Polynomial, can_assign_polynomial)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    Polynomial B;
    ASSERT_NO_THROW(A = B);
}

TEST(Polynomial, can_add_two_polynomials)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    Polynomial B(a);
    ASSERT_NO_THROW(A + B);
}

TEST(Polynomial, can_multiplicate_polynomial_by_monom)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    ASSERT_NO_THROW(A * a);
}

TEST(Polynomial, can_multiplicate_polynomial_by_const)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    ASSERT_NO_THROW(A * 2.5);
}

TEST(Polynomial, can_multiplicate_and_assign_polynomial_by_const)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    ASSERT_NO_THROW(A *= 2.5);
}

TEST(Polynomial, can_subtract_two_polynomials)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    Polynomial B(a);
    ASSERT_NO_THROW(A - B);
}

TEST(Polynomial, can_multiplicate_two_polynomials)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    Polynomial B(a);
    ASSERT_NO_THROW(A * B);
}

TEST(Polynomial, can_change_polynomial_to_true_form)
{
    Monom a(2, 2.5);
    Polynomial A(a);
    ASSERT_NO_THROW(A.truePolynomial());
}