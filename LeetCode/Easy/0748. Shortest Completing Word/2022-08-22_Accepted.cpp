class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> a = process(licensePlate);
        string ans;
        int minLen = 16;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].length() < minLen && complete(a, process(words[i]))) {
                minLen = words[i].length();
                ans = words[i];
            }
        }
        return ans;
    }

private:
    vector<int> process(string s) {
        vector<int> cnt(26, 0);
        for (int i = 0; i < s.length(); i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                cnt[s[i] - 'a']++;
            } else if ('A' <= s[i] && s[i] <= 'Z') {
                cnt[s[i] - 'A']++;
            }
        }
        return cnt;
    }
    
    bool complete(vector<int> a, vector<int> b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] > b[i]) return false;
        }
        return true;
    }
};