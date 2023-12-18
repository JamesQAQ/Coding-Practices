class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> val;
        for (int i = 0; i < mat.size(); i++) {
            val.push_back(getSoldierNum(mat[i]) * mat.size() + i);
        }
        stable_sort(val.begin(), val.end());
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(val[i] % mat.size());
        }
        return ans;
    }

private:
    int getSoldierNum(vector<int> &row) {
        int lpos = 0;
        int rpos = row.size() - 1;
        while (lpos <= rpos) {
            int mpos = (lpos + rpos) / 2;
            if (row[mpos] == 1) {
                lpos = mpos + 1;
            } else {
                rpos = mpos - 1;
            }
        }
        return lpos;
    }
};