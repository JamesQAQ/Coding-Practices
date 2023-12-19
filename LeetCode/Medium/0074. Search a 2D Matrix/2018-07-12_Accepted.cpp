class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int midx = mid / m;
            int midy = mid % m;
            int val = matrix[midx][midy];
            if (val > target) {
                r = mid - 1;
            } else if (val < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};