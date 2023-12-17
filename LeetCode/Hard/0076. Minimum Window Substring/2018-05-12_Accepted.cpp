class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        
        int nc[256] = {};
        int nct = 0;
        for (int i = 0; i < t.length(); i++) {
        	if (nc[t[i]] == 0) {
        		nct++;
			}
        	nc[t[i]]++;
		}
		
		int c[256] = {};
		int cnt = 0, rptr = 0;
		for (int i = 0; i < s.length(); i++) {
			while (cnt < nct && rptr < s.length()) {
				if (nc[s[rptr]] > 0) {
					c[s[rptr]]++;
					if (c[s[rptr]] == nc[s[rptr]]) {
						cnt++;
					}
				}
				rptr++;
			}
			if (cnt == nct) {
				string res = s.substr(i, rptr - i);
				if (ans.length() == 0 || res.length() < ans.length()) {
					ans = res;
				}
			}
			if (nc[s[i]] > 0) {
				if (c[s[i]] == nc[s[i]]) {
					cnt--;
				}
				c[s[i]]--;
			}
		}
        
        return ans;
    }
};