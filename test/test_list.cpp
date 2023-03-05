#include <gtest.h>
#include "list.hpp"

TEST(List, can_create_list)
{
    ASSERT_NO_THROW(List<int> list);
}

TEST(List, can_create_list_with_one_element)
{
    ASSERT_NO_THROW(List<int> list(1));
}

TEST(List, created_list_with_true_one_element)
{
    List<int> list(1);
    EXPECT_EQ(1, list.begin()->data);
}

TEST(List, true_when_list_is_empty)
{
    List<int> list;
    EXPECT_EQ(1, list.isEmpty());
}

TEST(List, false_when_list_is_not_empty)
{
    List<int> list(1);
    EXPECT_NE(1, list.isEmpty());
}

TEST(List, begin_is_nullptr_if_list_is_empty)
{
    List<int> list;
    EXPECT_EQ(nullptr , list.begin());
}

TEST(List, begin_is_first_node_when_list_is_not_empty)
{
    List<int> list(1);
    EXPECT_EQ(1, list.begin()->data);
}

TEST(List, can_use_method_size)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.size());
}

TEST(List, method_size_gets_true_size)
{
    List<int> list(1);
    EXPECT_EQ(1, list.size());
}

TEST(List, can_copy_empty_list)
{
    List<int> list;
    ASSERT_NO_THROW(List<int> list1(list));
}

TEST(List, can_copy_list_with_one_element)
{
    List<int> list(1);
    ASSERT_NO_THROW(List<int> list1(list));
}

TEST(List, copied_list_with_one_element_has_true_size)
{
    List<int> list(1);
    List<int> list1(list);
    EXPECT_EQ(1, list1.size());
}

TEST(List,copied_list_with_one_element_is_true)
{
    List<int> list(1);
    List<int> list1(list);
    EXPECT_EQ(1, list1.begin()->data);
}

TEST(List, copied_list_with_one_element_with_own_memory)
{
    List<int> list(1);
    List<int> list1(list);
    list1.begin()->data = 2;
    EXPECT_EQ(1, list.begin()->data);
}

TEST(List, can_copy_list_with_elements)
{
    List<int> list;
    for (int i = 0; i < 10; i++)
    {
        list.push_front(i);
    }
    ASSERT_NO_THROW(List<int> list1(list));
}

TEST(List, copied_list_with_elements_has_true_size)
{
    List<int> list;

    for (int i = 10; i > -1; i--)
        list.push_front(i);

    List<int> list1(list);
    EXPECT_EQ(11, list1.size());
}

TEST(List, copied_list_with_elements_is_true)
{
    List<int> list;

    for (int i = 10; i > -1; i--)
        list.push_front(i);

    List<int> list1(list);
    Node<int>* temp = list1.begin();
    for (size_t i = 0; i < list.size(); i++, temp = temp->next)
        EXPECT_EQ(i, temp->data);
}

TEST(List, copied_list_with_elements_with_own_memory)
{
    List<int> list;

    for (int i = 10; i > -1; i--)
        list.push_front(i);

    List<int> list1(list);
    Node<int>* o = list1.begin();
    Node<int>* t = list.begin();

    for (size_t i = 0; i < list.size(); i++, o = o->next, t = t->next)
    {
        t->data = 5;
        EXPECT_EQ(i, o->data);
    }
}

TEST(List, can_push_front_in_empty_list)
{
    List<int> list;
    ASSERT_NO_THROW(list.push_front(2));
}

TEST(List, push_front_increases_size_to_one_in_empty_list)
{
    List<int> list;
    list.push_front(2);
    EXPECT_EQ(1, list.size());
}

TEST(List, push_front_in_empty_list_creates_true_node)
{
    List<int> list;
    list.push_front(1);
    EXPECT_EQ(1, list.begin()->data);
}

TEST(List, can_push_front_in_list)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.push_front(2));
}

TEST(List, push_front_increases_size_one_one_in_list)
{
    List<int> list(1);
    list.push_front(2);
    EXPECT_EQ(2, list.size());
}

TEST(List, push_front_in_list_creates_true_node)
{
    List<int> list(1);
    list.push_front(2);
    EXPECT_EQ(2, list.begin()->data);
}

TEST(List, end_is_nullptr_if_list_is_empty)
{
    List<int> list;
    EXPECT_EQ(nullptr, list.end());
}

TEST(List, end_is_last_node_when_list_is_not_empty)
{
    List<int> list(1);
    list.push_front(2);
    EXPECT_EQ(1, list.end()->data);
}

TEST(List, can_push_back_in_empty_list)
{
    List<int> list;
    ASSERT_NO_THROW(list.push_back(2));
}

TEST(List, push_back_increases_size_to_one_in_empty_list)
{
    List<int> list;
    list.push_back(2);
    EXPECT_EQ(1, list.size());
}

TEST(List, push_back_in_empty_list_creates_true_node)
{
    List<int> list;
    list.push_back(1);
    EXPECT_EQ(1, list.begin()->data);
}

TEST(List, can_push_back_in_list)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.push_back(2));
}

TEST(List, push_back_increases_size_one_one_in_list)
{
    List<int> list(1);
    list.push_back(2);
    EXPECT_EQ(2, list.size());
}

TEST(List, push_back_in_list_creates_true_node)
{
    List<int> list(1);
    list.push_back(2);
    EXPECT_EQ(2, list.end()->data);
}

TEST(List, can_use_method_clear)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.clear());
}

TEST(List, method_clear_changes_size_to_zero)
{
    List<int> list(1);
    list.clear();
    EXPECT_EQ(0, list.size());
}

TEST(List, method_clear_changes_tail_to_nullptr)
{
    List<int> list(1);
    list.clear();
    EXPECT_EQ(1, list.isEmpty());
}

TEST(List, method_clear_delete_all_elements) // >><<
{
    List<int> list(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    Node<int>* array[4];
    array[0] = list.begin();
    array[1] = array[0]->next;
    array[2] = array[1]->next;
    array[3] = list.end();
    list.clear();
    for (size_t i = 0; i < 3; i++)
        EXPECT_NE(array[i]->next, array[i + 1]);
}

TEST(List, can_use_operator_equal_list_to_itself)
{
    List<int> list(2);
    ASSERT_NO_THROW(list == list);
}

TEST(List, using_operator_equal_list_to_itself_true)
{
    List<int> list(2);
    EXPECT_EQ(1, list == list);
}

TEST(List, can_use_operator_equal_empty_list)
{
    List<int> list;
    List<int> list1;
    ASSERT_NO_THROW(list == list1);
}

TEST(List, using_operator_equal_empty_list_true)
{
    List<int> list;
    List<int> list1;
    EXPECT_EQ(1, list == list1);
}

TEST(List, can_use_operator_equal_list_with_one_element)
{
    List<int> list(2);
    List<int> list1(2);
    ASSERT_NO_THROW(list == list1);
}

TEST(List, using_operator_equal_list_with_one_element_true)
{
    List<int> list(2);
    List<int> list1(2);
    EXPECT_EQ(1, list == list1);
}

TEST(List, using_operator_equal_list_with_one_element_false)
{
    List<int> list(3);
    List<int> list1(2);
    EXPECT_EQ(0, list == list1);
}

TEST(List, can_use_operator_equal_list)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1(2);
    list1.push_back(3);
    ASSERT_NO_THROW(list == list1);
}

TEST(List, using_operator_equal_list_true)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1(2);
    list1.push_back(3);
    EXPECT_EQ(1, list == list1);
}

TEST(List, using_operator_equal_list_false)
{
    List<int> list(2);
    list.push_back(5);
    List<int> list1(2);
    list1.push_back(3);
    EXPECT_EQ(0, list == list1);
}

TEST(List, using_operator_equal_list_with_other_size_false)
{
    List<int> list(2);
    list.push_back(3);
    list.push_back(3);
    List<int> list1(2);
    list1.push_back(3);
    EXPECT_EQ(0, list == list1);
}

TEST(List, can_use_operator_not_equal_list)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1(2);
    list1.push_back(3);
    ASSERT_NO_THROW(list == list1);
}

TEST(List, using_operator_not_equal_list_true)
{
    List<int> list(2);
    list.push_back(4);
    List<int> list1(2);
    list1.push_back(3);
    EXPECT_EQ(1, list != list1);
}

TEST(List, can_assign_list_to_itself)
{
    List<int> list(2);
    ASSERT_NO_THROW(list = list);
}

TEST(List, assign_list_to_itself_do_not_change_data)
{
    List<int> list(2);
    list = list;
    EXPECT_EQ(2, list.begin()->data);
}

TEST(List, can_assign_equal_size_list_with_one_element)
{
    List<int> list(3);
    List<int> list1(2);
    ASSERT_NO_THROW(list = list1);
}

TEST(List, assign_equal_size_list_with_one_element_true)
{
    List<int> list(2);
    List<int> list1(3);
    list = list1;
    EXPECT_EQ(true, list == list1);
}

TEST(List, can_assign_equal_size_list)
{
    List<int> list(3);
    List<int> list1(2);
    ASSERT_NO_THROW(list = list1);
}

TEST(List, assign_equal_size_list_true)
{
    List<int> list(2);
    list.push_back(4);
    List<int> list1(2);
    list1.push_back(3);
    list = list1;
    EXPECT_EQ(true, list == list1);
}

TEST(List, can_assign_not_equal_size_list_when_other_list_is_empty)
{
    List<int> list(3);
    List<int> list1;
    ASSERT_NO_THROW(list = list1);
}

TEST(List, assign_not_equal_size_list_when_other_list_is_empty_true)
{
    List<int> list(2);
    List<int> list1;
    list = list1;
    EXPECT_EQ(true, list == list1);
}

TEST(List, can_assign_not_equal_size_list_when_other_list_with_one_element)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1(2);
    ASSERT_NO_THROW(list = list1);
}

TEST(List, assign_not_equal_size_list_when_other_list_with_one_element_true)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1(2);
    list = list1;
    EXPECT_EQ(true, list == list1);
}

TEST(List, can_assign_not_equal_size_list)
{
    List<int> list(3);
    List<int> list1(2);
    list1.push_back(4);
    ASSERT_NO_THROW(list = list1);
}

TEST(List, assign_not_equal_size_list_true)
{
    List<int> list(2);
    List<int> list1(2);
    list1.push_back(3);
    list = list1;
    EXPECT_EQ(true, list == list1);
}

TEST(List, can_merge_two_lists)
{
    List<int> list(2);
    List<int> list1(2);
    ASSERT_NO_THROW(list.merge(list1));
}

TEST(List, merge_two_lists_true)
{
    List<int> list(1);
    list.push_back(3);
    list.push_back(4);
    List<int> list1(0);
    list1.push_back(2);
    list.merge(list1);
    Node<int>* temp = list.begin();
    for (size_t i = 0; i < 5; i++, temp = temp->next)
        EXPECT_EQ(i, temp->data);
}

TEST(List, can_splice_list)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1;
    List<int> list2;

    ASSERT_NO_THROW(list.splice(list1, list2));
}

TEST(List, splices_lists_have_true_size)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1;
    List<int> list2;
    
    list.splice(list1, list2);

    EXPECT_EQ(1, list1.size());
    EXPECT_EQ(1, list2.size());
}

TEST(List, splices_lists_have_true_data)
{
    List<int> list(2);
    list.push_back(3);
    List<int> list1;
    List<int> list2;

    list.splice(list1, list2);

    EXPECT_EQ(2, list1.begin()->data);
    EXPECT_EQ(3, list2.begin()->data);
}

TEST(List, can_splice_empty_list)
{
    List<int> list;
    List<int> list1;
    List<int> list2;

    ASSERT_NO_THROW(list.splice(list1, list2));
}

TEST(List, splices_lists_also_empty)
{
    List<int> list;
    List<int> list1;
    List<int> list2;

    list.splice(list1, list2);

    EXPECT_EQ(true, list1.isEmpty());
    EXPECT_EQ(true, list2.isEmpty());
}

TEST(List, can_splice_empty_list_on_two_not_empty_lists)
{
    List<int> list;
    List<int> list1(2);
    List<int> list2(3);

    ASSERT_NO_THROW(list.splice(list1, list2));
}

TEST(List, splices_not_empty_lists_will_be_empty)
{
    List<int> list;
    List<int> list1(2);
    List<int> list2(3);

    list.splice(list1, list2);

    EXPECT_EQ(true, list1.isEmpty());
    EXPECT_EQ(true, list2.isEmpty());
}

TEST(List, can_splice_list_on_two_not_empty_lists)
{
    List<int> list;
    List<int> list1(2);
    List<int> list2(3);

    ASSERT_NO_THROW(list.splice(list1, list2));
}

TEST(List, splices_not_empty_lists_will_be_not_empty)
{
    List<int> list(3);
    list.push_back(4);
    List<int> list1(2);
    List<int> list2(3);

    list.splice(list1, list2);

    EXPECT_EQ(1, list1.size());
    EXPECT_EQ(1, list2.size());
}

TEST(List, splices_not_empty_lists_will_have_true_data)
{
    List<int> list(3);
    list.push_back(4);
    List<int> list1(2);
    List<int> list2(3);

    list.splice(list1, list2);

    EXPECT_EQ(3, list1.begin()->data);
    EXPECT_EQ(4, list2.begin()->data);
}

TEST(List, can_splice_list_with_one_element)
{
    List<int> list(3);
    List<int> list1;
    List<int> list2;

    ASSERT_NO_THROW(list.splice(list1, list2));
}

TEST(List,splices_lists_from_list_with_one_element_have_true_size)
{
    List<int> list(3);
    List<int> list1;
    List<int> list2;

    list.splice(list1, list2);

    EXPECT_EQ(1, list1.size());
    EXPECT_EQ(0, list2.size());
}

TEST(List, splices_lists_from_list_with_one_element_have_true_data)
{
    List<int> list(3);
    List<int> list1;
    List<int> list2;

    list.splice(list1, list2);

    EXPECT_EQ(3, list1.begin()->data);
    EXPECT_EQ(nullptr, list2.begin());
}

TEST(List, can_sort_list)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);

    ASSERT_NO_THROW(list.sort());
}

TEST(List, sorted_list_is_true)
{
    List<int> list(3);
    Node<int>* temp = list.begin();
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);

    list.sort();

    for (size_t i = 0; i < list.size(); i++, temp = temp->next)
        EXPECT_EQ(i, temp->data);
}

TEST(List, can_find_node_in_list)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    ASSERT_NO_THROW(list.find(temp));
}

TEST(List, find_node_in_list_true)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    EXPECT_EQ(true, list.find(temp));
}

TEST(List, find_node_in_list_false)
{
    List<int> list(3);
    List<int> list1(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    Node<int>* cur = list1.begin();
    EXPECT_EQ(false, list.find(cur));
}

TEST(List, can_find_node_in_empty_list)
{
    List<int> list;
    Node<int>* temp = nullptr;
    ASSERT_NO_THROW(list.find(temp));
}

TEST(List, find_node_in_empty_list_true)
{
    List<int> list;
    Node<int>* temp = nullptr;
    EXPECT_EQ(true, list.find(temp));
}

TEST(List, can_find_node_in_list_with_one_element)
{
    List<int> list(1);
    Node<int>* temp = list.begin();
    ASSERT_NO_THROW(list.find(temp));
}

TEST(List, find_node_in_list_with_one_element_true)
{
    List<int> list;
    Node<int>* temp = list.begin();
    EXPECT_EQ(true, list.find(temp));
}

TEST(List, can_delete_next_node_in_list)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    ASSERT_NO_THROW(list.deleteNextNode(temp));
}

TEST(List, delete_next_node_in_list_true)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    Node<int>* fast = temp->next->next;
    list.deleteNextNode(temp);
    EXPECT_EQ(temp->next, fast);
}


TEST(List, delete_next_node_in_list_false)
{
    List<int> list(3);
    List<int> list1(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    Node<int>* fast = temp->next;
    Node<int>* slow = list1.begin();
    list.deleteNextNode(slow);
    EXPECT_EQ(temp->next, fast);
}

TEST(List, delete_next_node_in_list_decrease_size_on_one)
{
    List<int> list(3);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    list.deleteNextNode(temp);
    EXPECT_EQ(3, list.size());
}

TEST(List, can_delete_next_node_in_empty_list)
{
    List<int> list;
    Node<int>* temp = list.begin();
    ASSERT_NO_THROW(list.deleteNextNode(temp));
}

TEST(List, delete_next_node_in_empty_list_true)
{
    List<int> list;
    Node<int>* temp = list.begin();
    list.deleteNextNode(temp);
    EXPECT_EQ(nullptr, temp);
}

TEST(List, can_delete_tail_in_list)
{
    List<int> list(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* temp = list.begin();
    while (temp->next->next) temp = temp->next;
    ASSERT_NO_THROW(list.deleteNextNode(temp));
}

TEST(List, delete_tail_in_list_true)
{
    List<int> list(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    Node<int>* fast = list.begin();
    Node<int>* temp = list.end();
    while (fast->next->next) fast = fast->next;
    list.deleteNextNode(fast);
    EXPECT_NE(temp, list.end());
}

TEST(List, can_get_first_element_in_list)
{
    List<int> list(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    ASSERT_NO_THROW(list.pop_front());
}

TEST(List, first_element_in_list_true)
{
    List<int> list(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    EXPECT_EQ(1, list.pop_front());
}

TEST(List, getting_first_element_in_list_decrease_size_on_one)
{
    List<int> list(1);
    list.push_back(2);
    list.push_back(1);
    list.push_back(0);
    list.pop_front();
    EXPECT_EQ(3, list.size());
}

TEST(List, can_get_first_element_in_list_with_one_element)
{
    List<int> list(1);
    ASSERT_NO_THROW(list.pop_front());
}

TEST(List, first_element_in_list_with_one_element_true)
{
    List<int> list(1);
    EXPECT_EQ(1, list.pop_front());
}

TEST(List, true_increase_after_getting_element_in_list_with_one_element)
{
    List<int> list(1);
    list.pop_front();
    list.push_back(3);
    EXPECT_EQ(3, list.begin()->data);
}

TEST(List, throw_if_get_first_element_in_empty_list)
{
    List<int> list;
    ASSERT_ANY_THROW(list.pop_front());
}