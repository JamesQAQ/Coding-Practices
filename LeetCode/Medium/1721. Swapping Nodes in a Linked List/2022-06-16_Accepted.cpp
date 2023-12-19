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
    ListNode* swapNodes(ListNode* head, int k) {
        int listLength = getLength(head);
        int k2 = listLength + 1 - k;
        if (k2 < k) {
            swap(k, k2);
        }
        if (k == k2) {
            return head;
        }
        if (k == 1) {
            if (listLength == 2) {
                ListNode* res = head->next;
                head->next = nullptr;
                res->next = head;
                return res;
            } else {
                ListNode* preLast = getNode(head, listLength - 1);
                ListNode* last = preLast->next;
                preLast->next = head;
                last->next = head->next;
                head->next = nullptr;
                return last;
            }
        } else {
            ListNode* preFirst = getNode(head, k - 1);
            ListNode* first = preFirst->next;
            ListNode* preSecond = getNode(head, k2 - 1);
            ListNode* second = preSecond->next;
            swap(preFirst->next, preSecond->next);
            swap(first->next, second->next);
        }
        return head;
    }

private:
    int getLength(ListNode* head) {
        int res = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            cur = cur->next;
            res++;
        }
        return res;
    }

    ListNode* getNode(ListNode* head, int i) {
        ListNode* cur = head;
        while (i > 1) {
            cur = cur->next;
            i--;
        }
        return cur;
    }
};