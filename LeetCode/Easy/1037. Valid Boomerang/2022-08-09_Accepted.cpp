class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx = points[2][0] - points[0][0];
        int dy = points[2][1] - points[0][1];
        int dx2 = points[1][0] - points[0][0];
        int dy2 = points[1][1] - points[0][1];
        return dx * dy2 - dy * dx2 != 0;
    }
};