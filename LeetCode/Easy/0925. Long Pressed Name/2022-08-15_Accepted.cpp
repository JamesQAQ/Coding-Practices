class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        vector<pair<char, int>> a = process(name);
        vector<pair<char, int>> b = process(typed);
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].first != b[i].first) return false;
            if (a[i].second > b[i].second) return false;
        }
        return true;
    }

private:
    vector<pair<char, int>> process(string s) {
        vector<pair<char, int>> res;
        s += '.';
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != c) {
                res.push_back(make_pair(c, cnt));
                c = s[i];
                cnt = 0;
            }
            cnt++;
        }
        return res;
    }
};