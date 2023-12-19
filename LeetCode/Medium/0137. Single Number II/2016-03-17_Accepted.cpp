class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[63] = {};
        for (int i = 0; i < nums.size(); i++){
            long long val = nums[i];
            if (nums[i] < 0){
                val = nums[i] + 10000000000000LL;
            }
            for (int j = 62; j >= 0; j--){
                if (val & ((long long)1 << j))
                    count[j]++;
            }
        }
        long long ans = 0;
        for (int i = 62; i >= 0; i--){
            ans = 2 * ans + count[i] % 3;
        }
        if (ans >2147483647)
            ans -= 10000000000000LL;
        return ans;
    }
};
