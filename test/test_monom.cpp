#include <gtest.h>
#include "monom.h"

TEST(Monom, can_create_monom)
{
    ASSERT_NO_THROW(Monom a);
}

TEST(Monom, can_create_monom_with_data)
{
    ASSERT_NO_THROW(Monom a(2, -2.5));
}

TEST(Monom, created_monom_with_true_data)
{
    Monom a(2, -2.5);
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(-2.5, a.coef);
}

TEST(Monom, can_convert_double_to_monom)
{
    ASSERT_NO_THROW(Monom a(-2.5));
}

TEST(Monom, converting_monom_with_true_data)
{
    Monom a(-2.5);
    EXPECT_EQ(0, a.degree);
    EXPECT_EQ(-2.5, a.coef);
}

TEST(Monom, can_copy_monom)
{
    Monom a(-2.5);
    ASSERT_NO_THROW(Monom b(a));
}

TEST(Monom, copied_monom_with_true_data)
{
    Monom a(-2.5);
    Monom b(a);
    EXPECT_EQ(true, b.degree == a.degree);
    EXPECT_EQ(true, b.coef == a.coef);
}

TEST(Monom, can_assign_monom_to_itself)
{
    Monom a(2, 2.5);
    ASSERT_NO_THROW(a = a);
}

TEST(Monom, assign_monom_to_itself_do_not_change_data)
{
    Monom a(2, 2.5);
    a = a;
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}

TEST(Monom, can_assign_not_equal_monom)
{
    Monom a(2, 2.5);
    Monom b(3, 2.5);
    ASSERT_NO_THROW(a = b);
}

TEST(Monom, assign_not_equal_monom_true_data)
{
    Monom a(2, 2.5);
    Monom b(3, 2.5);
    a = b;
    EXPECT_EQ(true, a.degree == b.degree);
    EXPECT_EQ(true, a.coef == b.coef);
}

TEST(Monom, can_add_other_monom_with_equal_degree)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    ASSERT_NO_THROW(a + b);
}

TEST(Monom, throw_if_add_other_monom_with_not_equal_degree)
{
    Monom a(2, 2.5);
    Monom b(3, 2.5);
    ASSERT_ANY_THROW(a + b);
}

TEST(Monom, addition_doesnot_change_data)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a + b;
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}

TEST(Monom, true_addition)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a + b;
    EXPECT_EQ(2, c.degree);
    EXPECT_EQ(5.0, c.coef);
}

TEST(Monom, can_subtract_other_monom_with_equal_degree)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    ASSERT_NO_THROW(a - b);
}

TEST(Monom, throw_if_subtract_other_monom_with_not_equal_degree)
{
    Monom a(2, 2.5);
    Monom b(3, 2.5);
    ASSERT_ANY_THROW(a - b);
}

TEST(Monom, subtraction_doesnot_change_data)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a - b;
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}

TEST(Monom, true_subtraction)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a - b;
    EXPECT_EQ(2, c.degree);
    EXPECT_EQ(0.0, c.coef);
}

TEST(Monom, can_multiplicate_other_monom)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    ASSERT_NO_THROW(a * b);
}

TEST(Monom, throw_if_multiplication_degree_greater_than_9)
{
    Monom a(8, 2.5);
    Monom b(5, 2.5);
    ASSERT_ANY_THROW(a * b);
}

TEST(Monom, multiplication_doesnot_change_data)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a * b;
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}

TEST(Monom, true_multiplication)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    Monom c;
    c = a * b;
    EXPECT_EQ(4, c.degree);
    EXPECT_EQ((2.5 * 2.5), c.coef);
}

TEST(Monom, can_multiplicate_constant)
{
    Monom a(2, 2.5);
    ASSERT_NO_THROW(a * 2.5);
}

TEST(Monom, multiplication_on_constant_doesnot_change_data)
{
    Monom a(2, 2.5);
    Monom c;
    c = a * 2.5;
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}

TEST(Monom, true_multiplication_on_constant)
{
    Monom a(2, 2.5);
    Monom c;
    c = a * 2.5;
    EXPECT_EQ(2, c.degree);
    EXPECT_EQ((2.5 * 2.5), c.coef);
}

TEST(Monom, can_use_method_less)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a < b);
}

TEST(Monom, monom_less_than_other_because_his_degree_less)
{
    Monom a(2, 2.5);
    Monom b(5, 2.5);
    EXPECT_EQ(true, a < b);
}

TEST(Monom, monom_less_than_other_because_his_coef_less)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    EXPECT_EQ(true, a < b);
}

TEST(Monom, can_use_method_less_or_equal)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a <= b);
}

TEST(Monom, monom_less_or_equal_than_other_because_his_degree_less)
{
    Monom a(2, 2.5);
    Monom b(5, 2.5);
    EXPECT_EQ(true, a <= b);
}

TEST(Monom, monom_less_or_equal_than_other_because_his_coef_less)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    EXPECT_EQ(true, a <= b);
}

TEST(Monom, can_use_method_greater)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a > b);
}

TEST(Monom, monom_greater_than_other_because_his_degree_greater)
{
    Monom a(4, 2.5);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a > b);
}

TEST(Monom, monom_greater_than_other_because_his_coef_greater)
{
    Monom a(2, 2.51);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a > b);
}

TEST(Monom, can_use_method_greater_or_equal)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a >= b);
}

TEST(Monom, monom_greater_or_equal_than_other_because_his_degree_greater_or_equal)
{
    Monom a(4, 2.5);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a >= b);
}

TEST(Monom, monom_greater_or_equal_than_other_because_his_coef_greater_or_equal)
{
    Monom a(2, 2.51);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a >= b);
}

TEST(Monom, can_use_method_equal)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a == b);
}

TEST(Monom, two_monoms_equal)
{
    Monom a(2, 2.5);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a == b);
}

TEST(Monom, can_use_method_not_equal)
{
    Monom a(2, 2.5);
    Monom b(2, 2.51);
    ASSERT_NO_THROW(a == b);
}

TEST(Monom, two_monoms_not_equal)
{
    Monom a(3, 2.5);
    Monom b(2, 2.5);
    EXPECT_EQ(true, a != b);
}

TEST(Monom, can_use_method_setMonom)
{
    Monom a;
    ASSERT_NO_THROW(a.setMonom(2, 2.5));
}

TEST(Monom, method_setMonom_install_true_data)
{
    Monom a;
    a.setMonom(2, 2.5);
    EXPECT_EQ(2, a.degree);
    EXPECT_EQ(2.5, a.coef);
}