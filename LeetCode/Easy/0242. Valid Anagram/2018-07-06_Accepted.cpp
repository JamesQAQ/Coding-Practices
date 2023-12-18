#include <algorithm>
using std::stable_sort;

class Solution {
public:
    bool isAnagram(string s, string t) {
        stable_sort(s.begin(), s.end());
        stable_sort(t.begin(), t.end());
        return s == t;
    }
};