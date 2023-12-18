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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = listLength(headA);
        int lenB = listLength(headB);
        if (lenA > lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }
        headB = move(headB, lenB - lenA);
        int initStep = 1;
        while (initStep * 2 <= lenA) {
            initStep *= 2;
        }
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (initStep >= 1) {
            ListNode *newA = move(ptrA, initStep);
            ListNode *newB = move(ptrB, initStep);
            if (newA == NULL && newB == NULL) {
                // pass
            } else if ((newA == NULL && newB != NULL) || (newA != NULL && newB == NULL) || (newA->val != newB->val)) {
                ptrA = newA;
                ptrB = newB;
            }
            initStep /= 2;
        }
        if (ptrA == ptrB) return ptrA;
        return ptrA->next;
    }

private:
    int listLength(ListNode *head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode* move(ListNode *head, int step) {
        while (step--) {
            head = head->next;
            if (head == NULL) return NULL;
        }
        return head;
    }
};