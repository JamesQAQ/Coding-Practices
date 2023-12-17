class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int p = 0;
        int canTest = 1;
        int parameter = minutesToTest / minutesToDie + 1;
        while (canTest < buckets) {
            canTest *= parameter;
            p++;
        }
        return p;
    }
};