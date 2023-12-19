class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int cnt_p[26] = {};
        int cnt_s[26] = {};
        int cur_matched = 0;
        for (int i = 0; i < p.length(); i++) {
            cnt_p[p[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt_p[i] == 0) cur_matched++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (i - (int)p.length() >= 0) {
                char pre_char = s[i - (int)p.length()];
                int x = pre_char - 'a';
                if (cnt_s[x] == cnt_p[x]) {
                    cur_matched--;
                }
                cnt_s[x]--;
                if (cnt_s[x] == cnt_p[x]) {
                    cur_matched++;
                }
            }
            int x = s[i] - 'a';
            if (cnt_s[x] == cnt_p[x]) {
                cur_matched--;
            }
            cnt_s[x]++;
            if (cnt_s[x] == cnt_p[x]) {
                cur_matched++;
            }
            
            if (cur_matched == 26) {
                ans.push_back(i - p.length() + 1);
            }
        }
        return ans;
    }
};