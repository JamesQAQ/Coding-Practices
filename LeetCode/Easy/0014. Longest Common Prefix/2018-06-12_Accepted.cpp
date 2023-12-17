class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cur = "";
        for (int i = 0; i < strs.size(); i++) {
        	if (i == 0) {
        		cur = strs[i];
			} else {
				string res = "";
				for (int j = 0; j < cur.length() && j < strs[i].length(); j++) {
					if (cur[j] != strs[i][j]) break;
					res += cur[j];
				}
				cur = res;
			}
		}
		return cur;
    }
};