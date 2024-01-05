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
  ListNode* partition(ListNode* head, int x) {
    ListNode* less = new ListNode();
    ListNode* lessEnd = less;
    ListNode* greater = new ListNode();
    ListNode* greaterEnd = greater;
    while (head != NULL) {
      if (head->val < x) {
        lessEnd->next = head;
        lessEnd = lessEnd->next;
      } else {
        greaterEnd->next = head;
        greaterEnd = greaterEnd->next;
      }
      head = head->next;
    }
    lessEnd->next = greater->next;
    greaterEnd->next = NULL;
    return less->next;
  }
};
