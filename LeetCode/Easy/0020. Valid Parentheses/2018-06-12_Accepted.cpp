class Solution {
public:
    bool isValid(string s) {
    	vector<char> stk;
    	for (int i = 0; i < s.length(); i++) {
    		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
    			stk.push_back(s[i]);
			} else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
				if (stk.size() == 0) return false;
				
				if (s[i] == ')' && stk[stk.size() - 1] != '(') {
					return false;
				} else if (s[i] == ']' && stk[stk.size() - 1] != '[') {
					return false;
				} else if (s[i] == '}' && stk[stk.size() - 1] != '{') {
					return false;
				}
				
				stk.pop_back();
			}
		}
        return stk.size() == 0;
    }
};