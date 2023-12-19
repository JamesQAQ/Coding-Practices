class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        stable_sort(people.begin(), people.end());
        int ans = 0;
        int lpos = 0, rpos = people.size() - 1;
        while (lpos <= rpos) {
            if (lpos != rpos && limit - people[rpos] >= people[lpos]) {
                lpos++;
            }
            rpos--;
            ans++;
        }
        return ans;
    }
};