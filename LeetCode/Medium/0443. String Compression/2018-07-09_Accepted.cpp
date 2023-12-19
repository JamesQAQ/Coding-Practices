class Solution {
public:
    int compress(vector<char>& chars) {
        char curChar = 0;
        int curCnt = 0;
        int ptr = 0;
        for (int i = 0; i < chars.size(); i++) {
            if (chars[i] != curChar) {
                if (curCnt > 0) {
                    update(chars, ptr, curChar, curCnt);
                }
                curChar = chars[i];
                curCnt = 0;
            }
            curCnt++;
        }
        if (curCnt > 0) {
            update(chars, ptr, curChar, curCnt);
        }
        return ptr;
    }
private:
    void update(vector<char>& chars, int& ptr, char c, int cnt) {
        chars[ptr++] = c;
        if (cnt > 1) {
            string numString = to_string(cnt);
            for (int i = 0; i < numString.length(); i++) {
                chars[ptr++] = numString[i];
            }
        }
    }
};