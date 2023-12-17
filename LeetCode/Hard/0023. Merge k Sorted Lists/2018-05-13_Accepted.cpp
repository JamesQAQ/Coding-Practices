struct Heap {
	vector<ListNode*> h;
	
	void init() {
		h.clear();
	}
	
	bool empty() {
		return h.size() == 0;
	}
	
	int front() {
		return h[0]->val;
	}
	
	void updateFront() {
		h[0] = h[0]->next;
		if (h[0] == NULL) {
			pop();
		} else {
			down(0);
		}
	}
	
	void push(ListNode* ln) {
		h.push_back(ln);
		up(h.size() - 1);
	}
	
	void pop() {
		if (h.size() == 0) return;
		h[0] = h[h.size() - 1];
		h.pop_back();
		down(0);
	}
	
	void up(int x) {
		int f = x >> 1;
		while (f >= 0 && h[x]->val < h[f]->val) {
			ListNode* tmp = h[x];
			h[x] = h[f];
			h[f] = tmp;
			x = f;
			f >>= 1;
		}
	}
	
	void down(int x) {
		int f = x << 1;
		while (f < h.size()) {
			if (f + 1 < h.size() && h[f + 1]->val < h[f]->val) {
				f++;
			}
			if (h[f]->val >= h[x]->val) {
				break;
			}
			ListNode* tmp = h[x];
			h[x] = h[f];
			h[f] = tmp;
			x = f;
			f <<= 1;
		}
	}
} ;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* head = NULL;
		ListNode* ptr = NULL;
    	Heap heap;
    	heap.init();
    	for (int i = 0; i < lists.size(); i++) {
    		if (lists[i] != NULL) {
    			heap.push(lists[i]);
    		}
		}
		while (!heap.empty()) {
			if (head == NULL) {
				head = ptr = new ListNode(heap.front());
			} else {
				ptr->next = new ListNode(heap.front());
				ptr = ptr->next;
			}
			heap.updateFront();
		}
        return head;
    }
};