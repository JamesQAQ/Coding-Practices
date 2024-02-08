/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode* head) {
    deque<ListNode*> deq;
    ListNode* cur = head;
    while (cur != NULL) {
      deq.push_back(cur);
      cur = cur->next;
    }

    ListNode* pre = NULL;
    bool front = true;
    while (!deq.empty()) {
      ListNode* next = front ? deq.front() : deq.back();
      front ? deq.pop_front() : deq.pop_back();
      if (pre != NULL) {
        pre->next = next;
      }
      pre = next;
      front = !front;
    }
    pre->next = NULL;
  }
};
