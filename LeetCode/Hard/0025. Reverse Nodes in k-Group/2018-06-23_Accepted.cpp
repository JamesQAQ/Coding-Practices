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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur != NULL) {
            cur = cur->next;
            n++;
        }
        int group = n / k;
        if (group == 0) return head;
        
        cur = head;
        ListNode* pre = NULL;
        ListNode* next = NULL;
        ListNode* cur_group_end = NULL;
        ListNode* pre_group_end = NULL;
        ListNode* new_head = NULL;
        while (group--) {
            pre = NULL;
            cur_group_end = cur;
            for (int i = 0; i < k; i++) {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            if (pre_group_end != NULL) {
                pre_group_end->next = pre;
            } else {
                new_head = pre;
            }
            pre_group_end = cur_group_end;
        }
        cur_group_end->next = cur;
        return new_head;
    }
};