class Solution {
public:
    int mirrorReflection(int p, int q) {
        int h = p * q / gcd(p, q);
        int times = h / p;
        if (times % 2) {
            times = h / q;
            return 2 - times % 2;
        }
        return 0;
    }

private:
    int gcd(int m, int n) {
        if (m < n) swap(m, n);
        while (n != 0) {
            m %= n;
            swap(m, n);
        }
        return m;
    }
};