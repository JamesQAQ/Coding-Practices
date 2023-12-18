class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 2; i < points.size(); i++) {
            for (int j = 1; j < i; j++) {
                for (int k = 0; k < j; k++) {
                    int dx1 = points[j][0] - points[i][0];
                    int dy1 = points[j][1] - points[i][1];
                    int dx2 = points[k][0] - points[i][0];
                    int dy2 = points[k][1] - points[i][1];
                    ans = max(ans, abs(dx1 * dy2 - dy1 * dx2));
                }
            }
        }
        return ans * 0.5;
    }
};