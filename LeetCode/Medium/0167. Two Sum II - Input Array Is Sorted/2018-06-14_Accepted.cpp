class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int rptr = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++) {
            while (rptr > i && numbers[rptr] + numbers[i] > target) {
                rptr--;
            }
            if (rptr <= i) break;
            if (numbers[rptr] + numbers[i] == target) {
                ans.push_back(i + 1);
                ans.push_back(rptr + 1);
                break;
            }
        }
        return ans;
    }
};