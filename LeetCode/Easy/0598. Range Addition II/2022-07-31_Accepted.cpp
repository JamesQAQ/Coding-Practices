class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minA = m;
        int minB = n;
        for (int i = 0; i < ops.size(); i++) {
            minA = min(minA, ops[i][0]);
            minB = min(minB, ops[i][1]);
        }
        return minA * minB;
    }
};