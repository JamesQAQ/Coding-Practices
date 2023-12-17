class Solution {
public:
    int lengthOfLastWord(string s) {
    	int ans = 0;
    	int start = s.length() - 1;
    	while (start >= 0 && s[start] == ' ') {
			start--;
		}
        for (int i = start; i >= 0; i--) {
        	if (s[i] == ' ') break;
        	ans++;
		}
        return ans;
    }
};