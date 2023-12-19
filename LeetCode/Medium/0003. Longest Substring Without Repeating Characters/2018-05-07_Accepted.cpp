class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	int cnt[256] = {};
		int ans = 0, r_ptr = 0;
    	for (int i = 0; i < s.length(); i++) {
    		while (r_ptr < s.length() && cnt[s[r_ptr]] == 0) {
				cnt[s[r_ptr]]++;
				r_ptr++;
			}
			if (r_ptr - i > ans) ans = r_ptr - i;
			cnt[s[i]]--;
		}
        return ans;
    }
};