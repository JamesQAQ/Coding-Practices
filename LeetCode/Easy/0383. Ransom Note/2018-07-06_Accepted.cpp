class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {};
        for (int i = 0; i < magazine.length(); i++) {
            cnt[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.length(); i++) {
            int val = ransomNote[i] - 'a';
            if (cnt[val] <= 0) return false;
            cnt[val]--;
        }
        return true;
    }
};