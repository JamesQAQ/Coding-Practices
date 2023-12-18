class Solution {
    int f[31] = {0, 1};
    int num = 1;
    
public:
    int fib(int n) {
        while (n > num) {
            f[num + 1] = f[num] + f[num - 1];
            num++;
        }
        return f[n];
    }
};