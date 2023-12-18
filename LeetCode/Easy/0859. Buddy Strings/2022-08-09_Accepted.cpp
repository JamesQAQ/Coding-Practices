class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        vector<int> diff;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                diff.push_back(i);
                if (diff.size() > 2) return false;
            }
        }
        if (diff.size() == 0) {
            set<char> se;
            for (int i = 0; i < s.length(); i++) {
                if (se.find(s[i]) != se.end()) return true;
                se.insert(s[i]);
            }
            return false;
        } else {
            if (diff.size() != 2) return false;
            swap(s[diff[0]], s[diff[1]]);
            return s == goal;
        }
    }
};