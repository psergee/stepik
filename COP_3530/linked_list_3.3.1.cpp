#include <gtest/gtest.h>
#include <list>

/* Write a function find(Node* node, int valueInput) that starts at the
 * given node and returns the index of the node with the value valueInput.
 * Indices start at 0.  Return -1 if valueInput does not exist.
 *
 * Write a function add(Node* head, int index, int value) to add a node to a linked list. 
 * The head of the linked list is input, as well as the index where the node should be
 * added and the value associated with the node.  The program returns the head of the updated list.
 * If the index of insertion is greater than the size of the list, the program should return NULL.
 * 
 * Write the method std::string findInList(std::list<int> &myList, int valueToFind). The method
 * takes as arguments: a list and a value. The method implementation must create an iterator
 * and use the iterator to find the value in the list.  Return -1 if the item is not in the list.
 *
 * Given a singly linked list of integers that represents a data set (with head node head), return
 * the median of the data set.
 *
 */

struct Node
{
    int value;
    Node* next = nullptr;
};

int find(Node* node, int valueInput)
{
    size_t i = 0;
    for(; node && node->value != valueInput; node = node->next) ++i;
    return node ? i : -1;
}

Node* add(Node* head, int index, int valueInput)
{
    Node* prev = nullptr, *node = head;
    int i = 0;
    for(; node != nullptr && i != index; ++i)
    {
        prev = node;
        node = node->next;
    }
    if (!node && i != index)
        return nullptr;

    auto new_node = new Node{valueInput, node};
    if (prev)
        prev->next = new_node;
    else
        head = new_node;

    return head;
}

int findInList(std::list<int> &myList, int valueToFind)
{
    int i = 0;
    auto it = myList.cbegin();
    for(;it != myList.cend(); ++it, ++i)
    {
        if (*it == valueToFind)
            break;
    }
    if (it == myList.cend())
        return -1;
    return i;
}

float median(Node* head)
{
    unsigned size = 0;
    auto half = head;
    if (head)
        ++size, head = head->next;

    while(head)
    {
        if (!(size&1))
            half = half->next;
        head = head->next;
        ++size;
    }

    return (size&1) ? static_cast<float>(half->value) : (half->value + half->next->value)/2.;
}

TEST(LinkedList, NodeFind)
{
    Node d{4};
    Node c{3, &d};
    Node b{2, &c};
    Node a{1, &b};

    EXPECT_EQ(find(&a, 5), -1);
    EXPECT_EQ(find(&a, 4), 3);
    EXPECT_EQ(find(&a, 1), 0);
}

TEST(LinkedList, NodeAdd)
{
    Node d{4};
    Node c{3, &d};
    Node b{2, &c};
    Node a{1, &b};

// 1 2 3 4
    auto head = add(&a, 0, 0);

// 0 1 2 3 4
    head = add(head, 1, 5);

// 0 5 1 2 3 4
    EXPECT_EQ(add(head, 7, 10), nullptr);

    head = add(head, 6, 10);
// 0 5 1 2 3 4 10

    EXPECT_EQ(head->value, 0);

    auto node = head->next;
    EXPECT_EQ(node->value, 5);

    node = node->next;
    EXPECT_EQ(node->value, 1);
    node = node->next;
    EXPECT_EQ(node->value, 2);
    node = node->next;
    EXPECT_EQ(node->value, 3);
    node = node->next;
    EXPECT_EQ(node->value, 4);
    node = node->next;
    EXPECT_EQ(node->value, 10);
    node = node->next;
    EXPECT_EQ(node, nullptr);
}

TEST(LinkedList, FindValueIndex)
{
    std::list<int> l{1,2,3,4,5,6,7,8};
    EXPECT_EQ(findInList(l, 1), 0);
    EXPECT_EQ(findInList(l, 2), 1);
    EXPECT_EQ(findInList(l, 0), -1);
    EXPECT_EQ(findInList(l, 6), 5);
}

TEST(LinkedList, CalcMedian)
{
    Node d{4};
    Node c{3, &d};
    Node b{2, &c};
    Node a{1, &b};

    EXPECT_EQ(median(&a), 2.5f);
    c.next = nullptr;
    EXPECT_EQ(median(&a), 2.f);
    b.next = nullptr;
    EXPECT_EQ(median(&a), 1.5f);
    a.next = nullptr;
    EXPECT_EQ(median(&a), 1.f);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
