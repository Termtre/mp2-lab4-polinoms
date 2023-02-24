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
    Node<int>* temp;
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