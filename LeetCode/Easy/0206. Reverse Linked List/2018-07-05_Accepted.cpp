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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        dfs(NULL, head);
        return ans;
    }
private:
    ListNode* ans;
    
    void dfs(ListNode* pre, ListNode* cur) {
        if (cur->next == NULL) {
            ans = cur;
            cur->next = pre;
            return;
        }
        dfs(cur, cur->next);
        cur->next = pre;
    }
};