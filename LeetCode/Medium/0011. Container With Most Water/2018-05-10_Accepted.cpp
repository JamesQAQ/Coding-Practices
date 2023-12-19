struct Node {
	int h, idx;
	Node(int _h, int _idx) {
		h = _h;
		idx = _idx;
	}
} ;

class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<Node> l, r;
        for (int i = 0; i < height.size(); i++) {
        	if (l.size() == 0 || height[i] > l[l.size() - 1].h) {
        		l.push_back(Node(height[i], i));
			}
		}
		for (int i = height.size() - 1; i >= 0; i--) {
        	if (r.size() == 0 || height[i] > r[r.size() - 1].h) {
        		r.push_back(Node(height[i], i));
			}
		}
		int ans = gao(l, r);
		modify(l, height.size());
		modify(r, height.size());
		return max(ans, gao(r, l));
    }
private:
	int max(int a, int b) {
		return (a > b) ? a : b;
	}
	
	void modify(vector<Node>& a, int n) {
		for (int i = 0; i < a.size(); i++) {
			a[i].idx = n - a[i].idx - 1;
		}
	}
	
	int gao(vector<Node>& l, vector<Node>& r) {
		int r_ptr = 0, ans = 0;
		for (int i = 0; i < l.size(); i++) {
			while (r_ptr < r.size() && r[r_ptr].h < l[i].h) {
				r_ptr++;
			}
			if (r_ptr >= r.size()) break;
			if (r[r_ptr].idx <= l[i].idx) break;
			ans = max(ans, l[i].h * (r[r_ptr].idx - l[i].idx));
		}
		return ans;
	}
};
