#include <algorithm>
#include <string>

int gcd(int m, int n){
    while ((m %= n) && (n %= m));
    return (m == 0) ? n : m;
}

bool cmp(string a, string b){
    int lcm = a.length() * b.length() / gcd(a.length(), b.length());
    for (int i = 0; i < lcm; i++)
        if (a[i % a.length()] != b[i % b.length()])
            return a[i % a.length()] > b[i % b.length()];
    return true;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector <string> snums;
        char tmp[11];
        for (int i = 0; i < nums.size(); i++){
            sprintf(tmp, "%d", nums[i]);
            snums.push_back(string(tmp));
        }
        stable_sort(snums.begin(), snums.end(), cmp);
        string ans = "";
        for (int i = 0; i < snums.size(); i++)
            ans += snums[i];
        bool zero = true;
        for (int i = 0; i < ans.length(); i++)
            if (ans[i] != '0')
                zero = false;
        if (zero)
            return "0";
        return ans;
    }
};
