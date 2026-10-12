class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> sums(m, vector<int>(n, INT_MAX));
        sums[0][0] = grid[0][0];

        return findMinPathSum(grid, sums, m, n, m-1, n-1);
    }

    int findMinPathSum(vector<vector<int>>& grid, vector<vector<int>>& sums, int m, int n, int r, int c){
        if(r == 0 && c == 0) return grid[r][c];
        if(sums[r][c] != INT_MAX) return sums[r][c];

        int top = (inbound(m, n, r-1, c)) ? grid[r][c] + findMinPathSum(grid, sums, m, n, r-1, c) : INT_MAX;
        int left = (inbound(m, n, r, c-1)) ? grid[r][c] + findMinPathSum(grid, sums, m, n, r, c-1) : INT_MAX;

        int smalest = top > left ? left : top;

        sums[r][c] = smalest < sums[r][c] ? smalest : sums[r][c];

        return sums[r][c];
    }

    bool inbound(int m, int n, int r, int c){
        return (r >= 0 && c >= 0 && r < m && c < n);
    }
};