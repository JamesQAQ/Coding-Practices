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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* ans = new ListNode();
    ListNode* ansEnd = ans;
    while (head != NULL) {
      if (head->next == NULL
          || head->next != NULL && head->val != head->next->val) {
        ansEnd->next = head;
        ansEnd = ansEnd->next;
        head = head->next;
        ansEnd->next = NULL;
      } else {
        while (head->next != NULL && head->val == head->next->val) {
          head = head->next;
        }
        head = head->next;
      }
    }
    return ans->next;
  }
};
