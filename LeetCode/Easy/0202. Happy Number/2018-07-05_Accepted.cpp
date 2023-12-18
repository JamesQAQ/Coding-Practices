class Solution {
public:
    bool isHappy(int n) {
        set<int> appeared;
        while (n != 1) {
            if (appeared.find(n) != appeared.end()) {
                return false;
            }
            appeared.insert(n);
            n = transform(n);
        }
        return true;
    }
private:
    int transform(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};