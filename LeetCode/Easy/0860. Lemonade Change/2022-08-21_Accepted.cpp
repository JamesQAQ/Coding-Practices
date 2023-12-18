class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c = 0, c2 = 0;
        for (int i = 0; i < bills.size(); i++) {
            int b = bills[i] / 5;
            if (b == 1) c++;
            if (b == 2) {
                if (c == 0) return false;
                c--;c2++;
            }
            if (b == 4) {
                if ((c2 && c) || c > 2) {
                    if (c2 && c) {c2--;c--;} else {c-=3;}
                } else {return false;}
            }
        }
        return true;
    }
};