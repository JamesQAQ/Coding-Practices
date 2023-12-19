class Solution {
public:
    vector<string> letterCombinations(string digits) {
        init();
        vector<string> result;
        if (digits.length() == 0) return result;
        dfs(result, "", digits);
        return result;
    }

private:
	string s[256];
	void init() {
		s['2'] = "abc";
		s['3'] = "def";
		s['4'] = "ghi";
		s['5'] = "jkl";
		s['6'] = "mno";
		s['7'] = "pqrs";
		s['8'] = "tuv";
		s['9'] = "wxyz";
	}
	
	void dfs(vector<string> &result, string cur_str, string &digits) {
		if (cur_str.length() == digits.length()) {
			result.push_back(cur_str);
			return;
		}
		char d = digits[cur_str.length()];
		for (int i = 0; i < s[d].length(); i++) {
			dfs(result, cur_str + s[d][i], digits);
		}
	}
};