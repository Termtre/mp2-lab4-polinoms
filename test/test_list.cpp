#include <gtest.h>
#include "list.h"

TEST(List, can_create_list)
{
    ASSERT_NO_THROW(List<int> list);
}

TEST(List, can_create_list_with_element)
{
    ASSERT_NO_THROW(List<int> list(1));

}

TEST(List, can_get_node_from_list)
{
    List<int> list(0);
    ASSERT_NO_THROW(list.getNode(1));
    EXPECT_EQ(list.getNode(1), nullptr);
}

TEST(List, data_of_node_from_list_is_true)
{
    List<int> list(1);
    EXPECT_EQ(list.getNode(0)->data, 1);
}

TEST(List, can_create_list_from_array)
{
    int* array = new int[10];
    ASSERT_NO_THROW(List<int> list(array, 10));
    delete[] array;
}

TEST(List, can_sort_list)
{
    List<size_t> list;

    ASSERT_NO_THROW(list.sort(0, (static_cast<int>(list.size() - 1))));

    Node<size_t>* temp = list.getNode(0);

    for (size_t i = 0; i < list.size(); i++, temp = temp->next)
    {
        EXPECT_EQ(temp->data, i);
    }
}

TEST(List, list_is_empty_true)
{
    List<int> list;
    EXPECT_EQ(1, list.isEmpty());
}

TEST(List, list_is_empty_false)
{
    List<int> list(1);
    EXPECT_NE(1, list.isEmpty());
}

TEST(List, get_true_list_size)
{
    List<int> list(1);
    EXPECT_EQ(1, list.size());
}
// operator ==
TEST(List, can_compare_on_equal_two_lists)
{
    List<int> list1(1);
    List<int> list2(1);
    ASSERT_NO_THROW(list1 == list2);
}

TEST(List, two_lists_are_equal)
{
    List<int> list1(1);
    List<int> list2(1);
    EXPECT_EQ(true, (list1 == list2));
}
// operator !=
TEST(List, two_lists_are_not_equal)
{
    List<int> list1(1);
    List<int> list2(2);
    EXPECT_EQ(true, (list1 != list2));
}
// operator =
TEST(List, can_assign_lists_of_equal_size)
{
    List<int> list1(1);
    List<int> list2(2);
    ASSERT_NO_THROW(list1 = list2);
    EXPECT_EQ(list1.getNode(0)->data, list2.getNode(0)->data);
}

TEST(List, assign_operator_changes_list_size)
{
    List<int> list1(1);
    list1.push_front(2);
    List<int> list2(2);
    list2 = list1;
    EXPECT_EQ(2, list2.size());
}

TEST(List, can_assign_lists_of_non_equal_size)
{
    List<int> list1(1);
    list1.push_front(2);
    List<int> list2(2);
    ASSERT_NO_THROW(list2 = list1);
    list2 = list1;
    EXPECT_EQ(2, list1.size());
    EXPECT_EQ(2, list2.size());
}
// push_front
TEST(List, can_push_front_with_empty_list)
{
    List<int> list;
    ASSERT_NO_THROW(list.push_front(2));
}

TEST(List, push_front_with_empty_list_increases_size_on_one)
{
    List<int> list;
    list.push_front(2);
    EXPECT_EQ(1, list.size());
}

TEST(List, push_front_with_empty_list_adds_true_element)
{
    List<int> list;
    list.push_front(2);
    EXPECT_EQ(2, list.getNode(0)->data);
}

TEST(List, can_push_front_not_with_empty_list)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.push_front(2));
}

TEST(List, push_front_with_not_empty_list_increases_size_on_one)
{
    List<int> list(1);
    list.push_front(2);
    EXPECT_EQ(2, list.size());
}

TEST(List, push_front_with_not_empty_list_adds_on_first_position_true_element)
{
    List<int> list(1);
    list.push_front(2);
    EXPECT_EQ(2, list.getNode(0)->data);
}
// push_back
TEST(List, can_push_back_with_empty_list)
{
    List<int> list;
    ASSERT_NO_THROW(list.push_back(2));
}

TEST(List, push_back_with_empty_list_increases_size_on_one)
{
    List<int> list;
    list.push_back(2);
    EXPECT_EQ(1, list.size());
}

TEST(List, push_back_with_empty_list_adds_true_element)
{
    List<int> list;
    list.push_back(2);
    EXPECT_EQ(2, list.getNode(0)->data);
}

TEST(List, can_push_back_not_with_empty_list)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.push_back(2));
}

TEST(List, push_back_with_not_empty_list_increases_size_on_one)
{
    List<int> list(1);
    list.push_back(2);
    EXPECT_EQ(2, list.size());
}

TEST(List, push_back_with_not_empty_list_adds_on_last_position_true_element)
{
    List<int> list(1);
    list.push_back(2);
    EXPECT_EQ(2, list.getNode(1)->data);
}
//clear()
TEST(List, can_clear_list)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.clear());
}

TEST(List, method_clear_decreases_size_to_0)
{
    List<int> list(1);
    list.clear();
    EXPECT_EQ(true, list.isEmpty());
}
