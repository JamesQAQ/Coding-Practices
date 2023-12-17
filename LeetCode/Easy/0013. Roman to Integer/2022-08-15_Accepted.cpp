class Solution {
public:
    int romanToInt(string s) {
        int v[256];
        v['I'] = 1;
        v['V'] = 5;
        v['X'] = 10;
        v['L'] = 50;
        v['C'] = 100;
        v['D'] = 500;
        v['M'] = 1000;
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1) {
                if (v[s[i]] < v[s[i + 1]]) {
                    sum -= 2 * v[s[i]];
                }
            }
            sum += v[s[i]];
        }
        return sum;
    }
};