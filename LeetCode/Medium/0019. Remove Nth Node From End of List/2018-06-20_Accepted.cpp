/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre = head;
        ListNode* cur = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        if (cur == NULL) {
            return head->next;
        }
        while (cur->next != NULL) {
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};