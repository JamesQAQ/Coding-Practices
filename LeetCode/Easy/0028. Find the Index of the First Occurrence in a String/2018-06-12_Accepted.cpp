// https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

class Solution {
public:
    int strStr(string haystack, string needle) {
    	if (needle.length() == 0) return 0;

        vector<int> z;
        int cur = -1;
        z.push_back(cur);
        for (int i = 1; i < needle.size(); i++) {
        	while (cur != -1 && needle[cur + 1] != needle[i]) {
        		cur = z[cur];
			}
			if (needle[cur + 1] == needle[i]) {
				cur++;
			}
			z.push_back(cur);
		}
		cur = -1;
		for (int i = 0; i < haystack.size(); i++) {
			while (cur != -1 && needle[cur + 1] != haystack[i]) {
				cur = z[cur];
			}
			if (needle[cur + 1] == haystack[i]) {
				cur++;
			}
			if (cur == z.size() - 1) {
				return i - z.size() + 1;
			}
		}
		return -1;
    }
};