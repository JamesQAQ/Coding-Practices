class Solution {
public:
  Node* copyRandomList(Node* head) {
    map<Node*, Node*> mapping;
    return copy(head, mapping);
  }

private:
  Node* copy(Node* cur, map<Node*, Node*>& mapping) {
    if (cur == NULL) {
      return NULL;
    }
    if (mapping.find(cur) == mapping.end()) {
      mapping[cur] = new Node(cur->val);
      mapping[cur]->next = copy(cur->next, mapping);
      mapping[cur]->random = copy(cur->random, mapping);
    }
    return mapping[cur];
  }
};
