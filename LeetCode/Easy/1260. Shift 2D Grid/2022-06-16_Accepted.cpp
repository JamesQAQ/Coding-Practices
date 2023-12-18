class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int size = grid.size() * grid[0].size();
        k = k % size;
        
        vector<int> backup;
        for (int i = k; i > 0; i--) {
            backup.push_back(get(grid, size - i));
        }
        
        for (int i = size - 1; i >= k; i--) {
            set(grid, i, get(grid, i - k));
        }
        
        for (int i = 0; i < k; i++) {
            set(grid, i, backup[i]);
        }
        
        return grid;
    }

private:
    int get(vector<vector<int>>& grid, int x) {
        int rowSize = grid[0].size();
        return grid[x / rowSize][x % rowSize];
    }
    
    void set(vector<vector<int>>& grid, int x, int val) {
        int rowSize = grid[0].size();
        grid[x / rowSize][x % rowSize] = val;
    }
};