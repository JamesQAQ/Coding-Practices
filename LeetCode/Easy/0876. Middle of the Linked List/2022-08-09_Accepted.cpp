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
    ListNode* middleNode(ListNode* head) {
        ListNode* head2 = head;
        while (head2 != nullptr && head2->next != nullptr) {
            head = head->next;
            head2 = head2->next;
            if (head2 != nullptr && head2->next != nullptr) {
                head2 = head2->next;
            }
        }
        return head;
    }
};