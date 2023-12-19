#define MAX 2147483647

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle[triangle.size() - 1].size();
        vector<int> a(n, MAX);
        vector<int> b(n, MAX);
        vector<int>* pre = &a;
        vector<int>* now = &b;
        vector<int>* tmp;
        now->at(0) = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            tmp = pre;
            pre = now;
            now = tmp;
            for (int j = 0 ; j <= i; j++) {
                if (j > 0) {
                    now->at(j) = min(pre->at(j - 1), pre->at(j)) + triangle[i][j];
                } else {
                    now->at(j) = pre->at(j) + triangle[i][j];
                }
            }
        }
        int ans = MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, now->at(i));
        }
        return ans;
    }
};