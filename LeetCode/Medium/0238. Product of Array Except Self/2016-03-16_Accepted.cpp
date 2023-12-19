class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a, ans;
        int tmp = 1;
        for (int i = nums.size() - 1; i >= 0; i--){
            tmp *= nums[i];
            a.push_back(tmp);
        }
        tmp = 1;
        for (int i = 0; i < nums.size(); i++){
            if ((int)nums.size() - i - 2 >= 0){
                ans.push_back(tmp * a[nums.size() - i - 2]);
            }
            else{
                ans.push_back(tmp);
            }
            tmp *= nums[i];
        }
        return ans;
    }
};
