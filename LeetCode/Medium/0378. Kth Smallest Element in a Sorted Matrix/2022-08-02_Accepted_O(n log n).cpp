struct Cell {
    int val;
    int rowIdx;
    int colIdx;
};

struct cmp {
    bool operator() (Cell a, Cell b) {
        return a.val > b.val;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        priority_queue <Cell, vector<Cell>, cmp> pq;
        for (int i = 0; i < rowSize; i++) {
            pq.push({matrix[i][0], i, 0});
        }
        for (int i = 0; i < k - 1; i++) {
            Cell top = pq.top();
            pq.pop();
            if (top.colIdx + 1 < colSize) {
                pq.push({matrix[top.rowIdx][top.colIdx + 1], top.rowIdx, top.colIdx + 1});
            }
        }
        return pq.top().val;
    }
};