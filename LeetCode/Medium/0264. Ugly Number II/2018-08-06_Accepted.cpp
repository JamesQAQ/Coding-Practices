class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies;
        dfs(1, 0, uglies);
        stable_sort(uglies.begin(), uglies.end());
        return uglies[n - 1];
    }

private:
	int factor[3] = {2, 3, 5};
    void dfs(long long x, int pos, vector<int>& uglies) {
        if (x > 2147483647LL) return;
        uglies.push_back(x);
        for (int i = pos; i < 3; i++) {
        	dfs(x * factor[i], i, uglies);
		}
    }
};