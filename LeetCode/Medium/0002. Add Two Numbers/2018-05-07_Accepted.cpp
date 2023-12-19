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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* head = NULL;
    	ListNode* ptr = NULL;
    	int carry = 0;
    	while (l1 != NULL && l2 != NULL) {
    		int sum = l1->val + l2->val + carry;
			int val = sum % 10;
    		carry = sum / 10;
    		if (ptr == NULL) {
    			head = ptr = new ListNode(val);
			} else {
				ptr->next = new ListNode(val);
				ptr = ptr->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			int sum = l1->val + carry;
			int val = sum % 10;
    		carry = sum / 10;
    		if (ptr == NULL) {
    			head = ptr = new ListNode(val);
			} else {
				ptr->next = new ListNode(val);
				ptr = ptr->next;
			}
			l1 = l1->next;
		}
		while (l2 != NULL) {
			int sum = l2->val + carry;
			int val = sum % 10;
    		carry = sum / 10;
    		if (ptr == NULL) {
    			head = ptr = new ListNode(val);
			} else {
				ptr->next = new ListNode(val);
				ptr = ptr->next;
			}
			l2 = l2->next;
		}
		if (carry > 0) {
			ptr->next = new ListNode(carry);
		}
        return head;
    }
};