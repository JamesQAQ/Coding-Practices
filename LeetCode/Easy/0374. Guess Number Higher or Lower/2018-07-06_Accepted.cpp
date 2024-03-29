// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l <= r) {
            int mid = ((long long)l + r) / 2;
            int ret = guess(mid);
            if (ret == 0) return mid;
            else if (ret == 1) l = mid + 1;
            else r = mid - 1;
        }
    }
};