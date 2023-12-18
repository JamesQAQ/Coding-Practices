class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        stable_sort(g.begin(), g.end());
        stable_sort(s.begin(), s.end());
        int ptr = 0;
        for (int i = 0; i < g.size(); i++) {
            while (ptr < s.size() && s[ptr] < g[i]) {
                ptr++;
            }
            if (ptr < s.size()) {
                ans++;
                ptr++;
            }
        }
        return ans;
    }
};