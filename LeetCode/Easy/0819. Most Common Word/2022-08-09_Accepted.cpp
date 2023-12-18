class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> ban;
        for (int i = 0; i < banned.size(); i++) {
            ban.insert(banned[i]);
        }
        
        map<string, int> cnt;
        string word = "";
        paragraph += '.';
        for (int i = 0; i < paragraph.length(); i++) {
            char c = paragraph[i];
            if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
            if ('a' <= c && c <= 'z') {
                word += c;
            } else if (word.length() > 0) {
                if (cnt.find(word) == cnt.end()) {
                    cnt[word] = 0;
                }
                cnt[word]++;
                word = "";
            }
        }
        
        pair<string, int> ans;
        ans.second = 0;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            if (ban.find(it->first) == ban.end() && it->second > ans.second) {
                ans.first = it->first;
                ans.second = it->second;
            }
        }
        return ans.first;
    }
};