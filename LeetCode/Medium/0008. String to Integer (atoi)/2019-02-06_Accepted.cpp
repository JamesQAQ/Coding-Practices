class Solution {
public:
    int myAtoi(string str) {
        bool findFirstNumber = false;
        bool minus = false;
        long long result = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!findFirstNumber) {
                if (isWhiteSpace(str[i])) {
                    continue;
                } else if (isMinus(str[i])) {
                    findFirstNumber = true;
                    minus = true;
                } else if (isPlus(str[i])) {
                    findFirstNumber = true;
                } else {
                    findFirstNumber = true;
                    // back for next process
                    i--;
                }
            } else {
                if (isNumber(str[i])) {
                    result = result * 10 + str[i] - '0';
                    if (!minus) {
                        if (result > LL_INT_MAX) {
                            result = LL_INT_MAX;
                            break;
                        }
                    } else {
                        if (result > -LL_INT_MIN) {
                            result = -LL_INT_MIN;
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
        }
        result = (minus) ? -result : result;
        return result;
    }
    
private:
    long long LL_INT_MAX = 2147483647LL;
    long long LL_INT_MIN = -2147483648LL;
    
    bool isWhiteSpace(char c) {
        return c == ' ';
    }
    
    bool isNumber(char c) {
        return '0' <= c && c <= '9';
    }
    
    bool isMinus(char c) {
        return c == '-';
    }
    
    bool isPlus(char c) {
        return c == '+';
    }
};