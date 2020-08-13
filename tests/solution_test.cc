#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(TEST0, TEST0) {
  const vector<int> input0 = {1,2,3,4,5,6,7};
  int i = -1;
  SinglyLinkedList WorkVec(input0,i);
  EXPECT_EQ(7, WorkVec.size());
  EXPECT_EQ(false, WorkVec.empty());

  WorkVec.push_back(9);
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.push_front(8);
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.pop_front();
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.pop_back();
  EXPECT_EQ(7, WorkVec.back());

  ListNode *p = new ListNode(3);
  WorkVec.insert_after(p,4);
  ListNode *temp = new ListNode(0);
  temp = WorkVec.head_;
  while(temp->val != p->val)
  {
    temp = temp->next;
  }
  EXPECT_EQ(4,temp->val);
    
  int ith = 3;
  EXPECT_EQ(7,WorkVec.GetBackPointer()->val);
  EXPECT_EQ(3,WorkVec.GetIthPointer(ith)->val);
}

TEST(TEST1, TEST1) {
  const vector<int> input0 = {10,50,30,40,20};
  int i = -1;
  SinglyLinkedList WorkVec(input0,i);
  EXPECT_EQ(5, WorkVec.size());
  EXPECT_EQ(false, WorkVec.empty());

  WorkVec.push_back(9);
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.push_front(8);
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.pop_front();
  EXPECT_EQ(9, WorkVec.back());

  WorkVec.pop_back();
  EXPECT_EQ(20, WorkVec.back());

}


