class Solution {
public:
    int reverse(int x) {
        long long y = 0;
        bool negative = false;

        if (x < 0) {
            negative = true;
            x = -x;
        }

        while (x > 0) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        if (negative) {
            y = -y;
        }

        if (y < -2147483648LL || y > 2147483647) {
            y = 0;
        }

        return y;
    }
};