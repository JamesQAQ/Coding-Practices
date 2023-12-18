class Solution {
public:
    bool setb[100001] = {};

    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma = sum(aliceSizes);
        int sumb = sum(bobSizes);

        for (int i = 0; i < bobSizes.size(); i++) {
            setb[bobSizes[i]] = true;
        }

        vector<int> ans;
        for (int i = 0; i < aliceSizes.size(); i++) {
            int minus2b = suma - sumb - 2 * aliceSizes[i];
            int b = -minus2b / 2;
            if (minus2b % 2 == 0 && b >= 0 && b <= 100000 && setb[b]) {
                ans.push_back(aliceSizes[i]);
                ans.push_back(-minus2b / 2);
                break;
            }
        }
        return ans;
    }

    int sum(vector<int>& sizes) {
        int res = 0;
        for (int i = 0; i < sizes.size(); i++) {
            res += sizes[i];
        }
        return res;
    }
};
