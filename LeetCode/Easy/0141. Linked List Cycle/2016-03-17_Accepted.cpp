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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode *pre = head, *now = head->next;
        bool ans = false;
        while (now->next != NULL){
            ListNode *next = now->next;
            now->next = pre;
            pre = now;
            now = next;
            if (now == head){
                ans = true;
                break;
            }
        }
        return ans;
    }
};
