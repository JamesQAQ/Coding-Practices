class Solution {
public:
    string convert(string s, int numRows) {
    	if (numRows == 1) return s;
        string result = "";
        int size = 2 * (numRows - 1);
        for (int i = 0; i < numRows; i++) {
        	for (int j = 0; j * size < s.length(); j++) {
	        	int start = j * size;
	        	if (i == 0) {
        			result += getChar(s, start);
	        	} else if (i == numRows - 1) {
					result += getChar(s, start + numRows - 1);
	        	} else {
	        		result += getChar(s, start + i);
	        		result += getChar(s, start + size - i);
	        	}
	        }
		}
		return result;
    }

private:
	string getChar(string s, int idx) {
		if (idx >= s.length()) {
			return "";
		} else {
			string tmp;
			tmp.push_back(s[idx]);
			return tmp;
		}
	}
};