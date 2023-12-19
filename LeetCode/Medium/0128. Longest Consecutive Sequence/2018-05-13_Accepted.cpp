#define MOD 152377

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
        	push(exist, nums[i]);
		}
		for (int i = 0; i < nums.size(); i++) {
			int val = nums[i];
			if (!in(checked, val)) {
				push(checked, val);
				
				int l = 0, r = 0;
				while (in(exist, val - l - 1)) {
					push(checked, val - l - 1);
					l++;	
				}
				while (in(exist, val + r + 1)) {
					push(checked, val + r + 1);
					r++;
				}
				
				if (l + r + 1 > ans) {
					ans = l + r + 1;
				}
			}
		}
		return ans;
    }

private:
	vector<int> exist[MOD], checked[MOD];
	
	void push(vector<int> hash[], int val) {
		int idx = (val % MOD + MOD) % MOD;
		for (int i = 0; i < hash[idx].size(); i++) {
			if (hash[idx][i] == val) {
				return;
			}
		}
		hash[idx].push_back(val);
	}
	
	bool in(vector<int> hash[], int val) {
		int idx = (val % MOD + MOD) % MOD;
		for (int i = 0; i < hash[idx].size(); i++) {
			if (hash[idx][i] == val) {
				return true;
			}
		}
		return false;
	}
};