class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = 46340;
        while (l <= r) {
        	int mid = (l + r) / 2;
        	if (mid * mid > x) {
        		r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		return r;
    }
};