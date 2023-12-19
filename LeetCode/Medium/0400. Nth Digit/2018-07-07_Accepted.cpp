class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1, num = 9, from = 1;
        while (n > (long long)digit * num) {
            n -= digit * num;
            digit++;
            num *= 10;
            from *= 10;
        }
        int nthDigit = (n - 1) % digit;
        int offset = (n - 1) / digit;
        int curNum = from + offset;
        char s[11];
        sprintf(s, "%d", curNum);
        return s[nthDigit] - '0';
    }
};