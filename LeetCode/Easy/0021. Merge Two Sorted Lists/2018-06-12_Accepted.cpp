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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = NULL;
    	ListNode* cur;
    	while (l1 != NULL || l2 != NULL) {
    		int val;
    		if (l1 == NULL || (l2 != NULL && l2->val < l1->val)) {
    			val = l2->val;
    			l2 = l2->next;
			} else {
				val = l1->val;
				l1 = l1->next;
			}
			if (head == NULL) {
				head = cur = new ListNode(val);
			} else {
				ListNode* next = new ListNode(val);
				cur->next = next;
				cur = next;
			}
		}
        return head;
    }
};