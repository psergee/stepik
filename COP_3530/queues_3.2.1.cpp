#include <queue>
#include <gtest/gtest.h>

/* You are given a queue of integers. Check if the queue is valid.
A Valid queue is one in which the numbers are inserted in ascending order.
The queue (5, 44, 333) is a Valid queue while the queue (5,44,33) is not. */

bool checkValidity(std::queue<int> q)
{
    if (q.empty())
        return true;
    
    int val = q.front();
    q.pop();
    while(!q.empty() && q.front() >= val)
    {
        val = q.front();
        q.pop();
    }
    return q.empty()? true : false;
}

TEST(checkValidityTest, PositiveNos)
{
    std::queue<int> q;
    ASSERT_EQ(true, checkValidity(q));
    q.push(1);
    q.push(2);
    ASSERT_EQ(true, checkValidity(q));
    q.push(3);
    ASSERT_EQ(true, checkValidity(q));
    q.push(2);
    ASSERT_EQ(false, checkValidity(q));
}
 
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}