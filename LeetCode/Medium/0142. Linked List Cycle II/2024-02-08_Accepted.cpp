class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    ListNode* ptr1 = head;
    ListNode* ptr2 = head;
    while (ptr2 != NULL && ptr2->next != NULL) {
      ptr1 = ptr1->next;
      ptr2 = ptr2->next->next;
      if (ptr1 == ptr2) {
        ptr1 = head;
        while (ptr1 != ptr2) {
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
        }
        return ptr1;
      }
    }
    return NULL;
  }
};
