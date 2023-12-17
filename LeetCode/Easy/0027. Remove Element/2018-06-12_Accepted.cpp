class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0;
        for (int i = 0; i < nums.size(); i++) {
        	if (ptr <= i) ptr = i + 1;
        	if (nums[i] == val) {
        		while (ptr < nums.size() && nums[ptr] == val) {
        			ptr++;
				}
				if (ptr < nums.size()) {
					nums[i] = nums[ptr];
					nums[ptr] = val;
				} else {
					return i;
				}
			}
		}
		return nums.size();
    }
};