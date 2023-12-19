class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = -1e9;
        int r = 1e9;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(matrix, k, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    bool ok(vector<vector<int>>& matrix, int k, int val) {
        int cnt = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] <= val) cnt++;
                else break;
            }
            if (cnt >= k) return true;
        }
        return cnt >= k;
    }
};