class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
    	
    	int ptr = 1, pv = nums[0];
        for (int i = 1; i < nums.size(); i++) {
        	if (pv != nums[i]) {
        		nums[ptr++] = nums[i];
        		pv = nums[i];
			}
		}
		return ptr;
    }
};