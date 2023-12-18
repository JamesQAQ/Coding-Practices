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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL) {
            if (cur->val == val) {
                if (pre == NULL) {
                    ans = cur->next;
                } else {
                    pre->next = cur->next;
                }
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return ans;
    }
};