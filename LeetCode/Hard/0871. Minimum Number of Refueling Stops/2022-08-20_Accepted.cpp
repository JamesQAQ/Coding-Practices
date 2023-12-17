class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        int f = startFuel;
        int pos = 0;
        priority_queue<int> q;
        while (f < target) {
            while (pos < stations.size() && f >= stations[pos][0]) {
                q.push(stations[pos++][1]);
            }
            if (q.empty()) return -1;
            f += q.top();
            q.pop();
            ans++;
        }
        return ans;
    }
};