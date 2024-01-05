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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) {
      return head;
    }
    ListNode* cur = new ListNode(0, head);
    head = cur;
    for (int i = 0; i < right; i++) {
      cur = cur->next;
    }
    ListNode* reversedHead = cur;
    ListNode* afterRight = cur->next;
    ListNode* pre;
    cur = head;
    for (int i = 0; i < left; i++) {
      pre = cur;
      cur = cur->next;
    }
    pre->next = reversedHead;
    pre = afterRight;
    for (int i = left; i <= right; i++) {
      ListNode* next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return head->next;
  }
};
