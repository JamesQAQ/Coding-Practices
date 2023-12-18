class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        unsigned int base = 16;
        string res = "";
        while (n > 0) {
            res += hex(n % base);
            n /= base;
        }
        for (int i = 0; i < res.length() / 2; i++) {
            char tmp = res[i];
            res[i] = res[res.length() - i - 1];
            res[res.length() - i - 1] = tmp;
        }
        return res;
    }
private:
    char hex(unsigned int x) {
        if (x < 10) return x + '0';
        else return x - 10 + 'a';
    }
};