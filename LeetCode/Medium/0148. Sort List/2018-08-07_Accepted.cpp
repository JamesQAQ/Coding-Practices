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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        return mergeSort(head);
    }

private:
    ListNode* mergeSort(ListNode* head) {
        int len = getLength(head);
        if (len == 1) return head;
        
        int llen = len / 2;
        
        ListNode* lptr = head;
        ListNode* ptr = head;
        
        for (int i = 0; i < llen - 1; i++) {
            ptr = ptr->next;
        }
        ListNode* rptr = ptr->next;
        ptr->next = NULL;
        
        lptr = mergeSort(lptr);
        rptr = mergeSort(rptr);
        
        // merge
        ListNode* newHead = NULL;
        if (lptr->val < rptr->val) {
            newHead = lptr;
            lptr = lptr->next;
        } else {
            newHead = rptr;
            rptr = rptr->next;
        }
        ListNode* curPtr = newHead;
        for (int i = 0; i < len - 1; i++) {
            if (rptr == NULL || (lptr != NULL && lptr->val < rptr->val)) {
                curPtr->next = lptr;
                lptr = lptr->next;
            } else {
                curPtr->next = rptr;
                rptr = rptr->next;
            }
            curPtr = curPtr->next;
        }
        return newHead;
    }
    
    int getLength(ListNode* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
};