class Solution {
public:
    void merge(vector<int>& res, int m, vector<int>& nums2, int n) {
    	vector<int> nums1;
        for (int i = 0; i < m; i++) {
        	nums1.push_back(res[i]);
		}
		int lptr = 0;
		int rptr = 0;
		for (int i = 0; i < m + n; i++) {
			if (lptr < m && (rptr >= n || nums1[lptr] < nums2[rptr])) {
				res[i] = nums1[lptr++];
			} else {
				res[i] = nums2[rptr++];
			}
		}
    }
};
