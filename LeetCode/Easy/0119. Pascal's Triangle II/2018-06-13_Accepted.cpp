class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for (int i = 0; i < rowIndex + 1; i++) {
            for (int j = i - 1; j > 0; j--) {
                ans[j] += ans[j - 1];
            }
            ans.push_back(1);
        }
        return ans;
    }
};