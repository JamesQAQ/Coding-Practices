class Solution {

public:
    int brokenCalc(int startValue, int target) {
        if (startValue >= target) {
            return startValue - target;
        }
        int currentValue = startValue;
        for (int ans = 0; ; ans++) {
            int doubleOperation = calcExpectedOperations(2 * currentValue, target);
            int minusOperation = calcExpectedOperations(currentValue - 1, target);
            if (doubleOperation < minusOperation) {
                currentValue *= 2;
            } else {
                currentValue -= 1;
            }
            if (currentValue == target) {
                return ans + 1;
            }
        }
        return -1;
    }

private:
    int calcExpectedOperations(int currentValue, int target) {
        if (currentValue == 0) {
            return 2147483647;
        }
        int res = 0;
        while (currentValue < target) {
            currentValue *= 2;
            res++;
        }
        return res + currentValue - target;
    }
};
