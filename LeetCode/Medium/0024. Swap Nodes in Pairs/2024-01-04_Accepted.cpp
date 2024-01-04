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
  ListNode* swapPairs(ListNode* head) {
    if (head == NULL) {
      return NULL;
    }
    ListNode* cur = head;
    ListNode* pre = NULL;
    head = NULL;
    while (cur != NULL) {
      if (cur->next == NULL) {
        if (head == NULL) {
          head = cur;
        }
        break;
      }
      if (pre != NULL) {
        pre->next = cur->next;
      }
      pre = cur;
      cur = cur->next;
      ListNode* tmp = cur->next;
      cur->next = pre;
      pre->next = tmp;
      if (head == NULL) {
        head = cur;
      }
      cur = tmp;
    }
    return head;
  }
};
