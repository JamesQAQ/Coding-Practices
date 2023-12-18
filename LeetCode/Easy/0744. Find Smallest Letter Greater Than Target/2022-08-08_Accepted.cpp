class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if (target >= letters[letters.size() - 1]) return letters[0];
        for (int i = 0; i < letters.size(); i++) {
            if (target < letters[i]) return letters[i];
        }
        return '!';
    }
};