class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> j;
        for (int i = 0; i < jewels.length(); i++) j.insert(jewels[i]);
        int ans = 0;
        for (int i = 0; i < stones.length(); i++) {
            if (j.find(stones[i]) != j.end()) ans++;
        }
        return ans;
    }
};
