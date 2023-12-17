class Solution {
public:
    string shortestPalindrome(string s) {
        string ps = preProcess(s);
        vector<int> p;
        for (int i = 0; i < ps.length(); i++) {
            p.push_back(0);
        }

        p[0] = 1;
        int idx = 0, r = 0;
        for (int i = 1; i < ps.length(); i++) {
            p[i] = 1;
            if (i <= r) {
                p[i] = min(r - i + 1, p[2 * idx - i]);
            }
            while (i - p[i] >= 0 && i + p[i] < ps.length() && ps[i - p[i]] == ps[i + p[i]]) {
                p[i]++;
            }
            if (i + p[i] - 1 > r) {
                idx = i;
                r = i + p[i] - 1;
            }
        }

        int ll = 0;
        for (int i = 0; i < p.size(); i++) {
            if (i - p[i] + 1 == 0) {
                if (p[i] - 1 > ll) {
                    ll = p[i] - 1;
                }
            }
        }

        string suffix = s.substr(ll, s.length() - ll);
        string ans = reverse(suffix) + s;

        return ans;
    }
private:
    string preProcess(string s) {
        string res = "#";
        for (int i = 0; i < s.length(); i++) {
            res += s[i];
            res += "#";
        }
        return res;
    }

    string reverse(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            char tmp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = tmp;
        }
        return s;
    }

    int min(int a, int b) {
        return (a < b) ? a : b;
    }
};