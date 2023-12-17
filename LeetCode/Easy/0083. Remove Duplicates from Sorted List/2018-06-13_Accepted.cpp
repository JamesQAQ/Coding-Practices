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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (head == NULL) return NULL;
    	
    	ListNode* cur = head;
    	ListNode* ptr = head;
    	
    	while (ptr != NULL) {
    		if (ptr->val != cur->val) {
    			cur->next = ptr;
    			cur = ptr;
			}
			ptr = ptr->next;
		}
		cur->next = NULL;
        
		return head;
    }
};
