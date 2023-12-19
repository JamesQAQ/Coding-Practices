class Solution {
public:
    int getSum(int a, int b) {
        while (true) {
            int and_val = a & b;
            if (and_val == 0) {
                return a | b;
            }
            int next_a = a ^ b;
            int next_b = and_val << 1;
            a = next_a;
            b = next_b;
        }
    }
};