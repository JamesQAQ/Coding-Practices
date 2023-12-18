class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        else if (num < 0) return "-" + process(-num);
        return process(num);
    }
    
private:
    string process(int num) {
        string res = "";
        while (num > 0) {
            res += num % 7 + '0';
            num /= 7;
        }
        for (int i = 0; i < res.length() / 2; i++) {
            swap(res[i], res[res.length() - i - 1]);
        }
        return res;
    }
};