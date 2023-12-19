class Solution {
public:
    string intToRoman(int num) {
        string mapping[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}
                                ,{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}
                                ,{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}
                                ,{"", "M", "MM", "MMM", "", "", "", "", "", ""}};
        int pow10[4] = {1, 10, 100, 1000};
        string ans = "";
        for (int i = 3; i >= 0; i--){
            ans += mapping[i][num / pow10[i]];
            num %= pow10[i];
        }
        return ans;
    }
};
