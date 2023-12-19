class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            tmp ^= nums[i];
        int a = 0, b = 0;
        tmp = tmp & (-tmp);
        for (int i = 0; i < n; i++){
            if (tmp & nums[i])
                a ^= nums[i];
            else
                b ^= nums[i];
        }
        vector <int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
