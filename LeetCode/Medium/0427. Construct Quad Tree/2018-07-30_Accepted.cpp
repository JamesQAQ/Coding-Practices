/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return dfs(0, grid[0].size() - 1, 0, grid.size() - 1, grid);
    }

private:
    Node* dfs(int left, int right, int top, int bottom, vector<vector<int>>& grid) {
        bool isLeaf = true;
        int topLeftVal = grid[top][left];
        for (int i = top; i <= bottom; i++) {
            if (!isLeaf) break;
            for (int j = left; j <= right; j++) {
                if (grid[i][j] != topLeftVal) {
                    isLeaf = false;
                    break;
                }
            }
        }
        if (isLeaf) {
            return new Node(topLeftVal == 1, true, NULL, NULL, NULL, NULL);
        } else {
            return new Node(true
                            , false
                            , dfs(left, (left + right) / 2, top, (top + bottom) / 2, grid)
                            , dfs((left + right) / 2 + 1, right, top, (top + bottom) / 2, grid)
                            , dfs(left, (left + right) / 2, (top + bottom) / 2 + 1, bottom, grid)
                            , dfs((left + right) / 2 + 1, right, (top + bottom) / 2 + 1, bottom, grid)
                           );
        }
    }
};