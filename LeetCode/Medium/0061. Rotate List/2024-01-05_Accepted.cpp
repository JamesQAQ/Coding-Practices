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
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL) {
      return head;
    }

    int length = 0;
    ListNode* end;
    ListNode* cur = head;
    while (cur != NULL) {
      length++;
      if (cur->next == NULL) {
        end = cur;
      }
      cur = cur->next;
    }
    end->next = head;
    k = k % length;

    cur = head;
    for (int i = 0; i < length - k - 1; i++) {
      cur = cur->next;
    }
    ListNode* ans = cur->next;
    cur->next = NULL;
    return ans;
  }
};
