class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector <int> mask;
        for (int i = 0; i < words.size(); i++){
            int tmp = 0;
            for (int j = 0; j < words[i].length(); j++)
                tmp |= (1 << (words[i][j] - 'a'));
            mask.push_back(tmp);
        }
        int ans = 0;
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if ((mask[i] & mask[j]) == 0){
                    int val = words[i].length() * words[j].length();
                    if (val > ans)
                        ans = val;
                }
        return ans;
    }
};
