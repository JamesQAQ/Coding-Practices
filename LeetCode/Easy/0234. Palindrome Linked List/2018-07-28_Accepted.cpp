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
    bool isPalindrome(ListNode* head) {
        int len = listLength(head);
        ListNode* pre = NULL;
        ListNode* ptr = head;
        for (int i = 0; i < len / 2; i++) {
            ListNode* next = ptr->next;
            ptr->next = pre;
            pre = ptr;
            ptr = next;
        }
        ListNode* lptr = pre;
        if (len % 2 == 1) ptr = ptr->next;
        while (lptr != NULL && ptr != NULL) {
            if (lptr->val != ptr->val) return false;
            lptr = lptr->next;
            ptr = ptr->next;
        }
        return true;
    }

private:
    int listLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
};