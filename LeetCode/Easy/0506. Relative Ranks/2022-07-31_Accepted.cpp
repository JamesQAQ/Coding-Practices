struct Score {
    int score;
    int idx;
};

bool cmp(Score i, Score j) {
    return i.score > j.score;
}

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<Score> a;
        for (int i = 0; i < score.size(); i++) {
            a.push_back({score[i], i});
        }
        stable_sort(a.begin(), a.end(), cmp);
        
        vector<string> ans(score.size());
        for (int i = 0; i < a.size(); i++) {
            string place = to_string(i + 1);
            if (i == 0) {
                place = "Gold Medal";
            } else if (i == 1) {
                place = "Silver Medal";
            } else if (i == 2) {
                place = "Bronze Medal";
            }
            ans[a[i].idx] = place;
        }
        return ans;
    }
};