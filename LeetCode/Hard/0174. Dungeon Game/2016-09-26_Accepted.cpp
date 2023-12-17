#define MAX 2147483646

struct Node {
   int x, y;
   Node(int _x, int _y) {
       x = _x;
       y = _y;
   }
} ;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 1, r = MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok(mid, dungeon))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
private:
    bool ok(int hp, vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int> row;
        vector<vector<int>> dp;
        vector<bool> brow;
        vector<vector<bool>> visited;
        for (int i = 0; i < n; i++) {
            dp.push_back(row);
            visited.push_back(brow);
            for (int j = 0; j < m; j++) {
                dp[i].push_back(0);
                visited[i].push_back(false);
            }
        }
        queue<Node> que;
        if (dungeon[0][0] + hp > 0) {
            dp[0][0] = dungeon[0][0];
            visited[0][0] = true;
        }
        else
            return false;
        Node tmp(0, 0);
        que.push(tmp);
        while (!que.empty()) {
            Node now = que.front();
            que.pop();
            int x = now.x, y = now.y;
            if (x == n - 1 && y == m - 1)
                return true;
            if (x < n - 1) {
                if (dp[x][y] + dungeon[x + 1][y] + hp > 0) {
                    if (visited[x + 1][y])
                        dp[x + 1][y] = max(dp[x + 1][y], dp[x][y] + dungeon[x + 1][y]);
                    else {
                        dp[x + 1][y] = dp[x][y] + dungeon[x + 1][y];
                        visited[x + 1][y] = true;
                        tmp.x = x + 1;
                        tmp.y = y;
                        que.push(tmp);
                    }
                }
            }
            if (y < m - 1) {
                if (dp[x][y] + dungeon[x][y + 1] + hp > 0) {
                    if (visited[x][y + 1])
                        dp[x][y + 1] = max(dp[x][y + 1], dp[x][y] + dungeon[x][y + 1]);
                    else {
                        dp[x][y + 1] = dp[x][y] + dungeon[x][y + 1];
                        visited[x][y + 1] = true;
                        tmp.x = x;
                        tmp.y = y + 1;
                        que.push(tmp);
                    }
                }
            }
        }
        return false;
    }
};
