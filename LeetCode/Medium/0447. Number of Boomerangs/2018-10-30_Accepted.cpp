class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
            map<int, int> dis_set;
            for (int j = 0; j < points.size(); j++) {
                if (i != j) {
                    int d = dis(points[i], points[j]);
                    if (dis_set.find(d) != dis_set.end()) {
                        dis_set[d]++;
                    } else {
                        dis_set[d] = 1;
                    }
                }
            }
            for (map<int, int>::iterator it = dis_set.begin(); it != dis_set.end(); it++) {
                ans += it->second * (it->second - 1);
            }
        }
        return ans;
    }

private:
    int dis(pair<int, int>& x, pair<int, int>& y) {
        int dx = x.first - y.first;
        int dy = x.second - y.second;
        return dx * dx + dy * dy;
    }
};