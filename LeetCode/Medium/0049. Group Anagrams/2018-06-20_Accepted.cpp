#include <unordered_map>
using std::unordered_map;

#include <algorithm>
using std::stable_sort;

#define COE 29
#define MOD 1000000007

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> um;
        for (int i = 0; i < strs.size(); i++) {
            um[minimalExpression(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto p : um) {
            ans.push_back(p.second);
        }
        return ans;
    }
private:
    long long minimalExpression(string s) {
        stable_sort(s.begin(), s.end());
        long long sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum = (sum * COE + s[i] - 'a') % MOD;
        }
        sum = (sum * COE + s.length()) % MOD;
        return sum;
    }
};