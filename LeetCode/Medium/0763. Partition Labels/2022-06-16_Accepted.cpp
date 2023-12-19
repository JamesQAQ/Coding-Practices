class Solution {
    int first[26], last[26];
    
public:
    vector<int> partitionLabels(string s) {
        for (int i = 0; i < 26; i++) {
            first[i] = -1;
        }
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (first[index] == -1) {
                first[index] = i;
            }
            last[index] = i;
        }
        
        vector<int> res;
        int kindCount = 0;
        int startFrom = 0;
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - 'a';
            if (first[index] == i) {
                kindCount++;
            }
            if (last[index] == i) {
                kindCount--;
            }
            if (kindCount == 0) {
                res.push_back(i - startFrom + 1);
                startFrom = i + 1;
            }
        }
        return res;
    }
};