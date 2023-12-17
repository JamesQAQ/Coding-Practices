class Solution {
public:
    bool isPalindrome(int X) {
        long long x = X;
        if (x < 0)
            return false;
        long long tmp = 1;
        while (tmp * 10 <= x)
            tmp *= 10;
        long long tmp2 = 1;
        while (tmp2 < tmp){
            int l = x / tmp;
            x %= tmp;
            tmp /= 10;
            int r = (x % (tmp2 * 10)) / tmp2;
            tmp2 *= 10;
            if (l != r)
                return false;
        }
        return true;
    }
};
