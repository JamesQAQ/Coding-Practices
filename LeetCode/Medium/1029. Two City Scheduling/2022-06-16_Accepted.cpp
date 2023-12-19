class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<int> deltas;
        int sum = 0;
        for (int i = 0; i < costs.size(); i++) {
            deltas.push_back(costs[i][0] - costs[i][1]);
            sum += costs[i][1];
        }
        stable_sort(deltas.begin(), deltas.end());
        for (int i = 0; i < deltas.size() / 2; i++) {
            sum += deltas[i];
        }
        return sum;
    }
};