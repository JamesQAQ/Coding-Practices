class Solution {
    string m[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> t;
        for (int i = 0; i < words.size(); i++) {
            t.insert(trans(words[i]));
        }
        return t.size();
    }
    
private:
    string trans(string word) {
        string res = "";
        for (int i = 0; i < word.length(); i++) {
            res += m[word[i] - 'a'];
        }
        return res;
    }
};