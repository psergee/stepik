#include <gtest/gtest.h>

/* Write a function find(Node* node, int valueInput) that starts at the
 * given node and returns the index of the node with the value valueInput.
 * Indices start at 0.  Return -1 if valueInput does not exist.
 *
 * Write a function add(Node* head, int index, int value) to add a node to a linked list. 
 * The head of the linked list is input, as well as the index where the node should be
 * added and the value associated with the node.  The program returns the head of the updated list.
 * If the index of insertion is greater than the size of the list, the program should return NULL.
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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
