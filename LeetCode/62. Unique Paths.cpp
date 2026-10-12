class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        return findUniquePaths(grid, m, n, 0, 0);
    }
    
    int findUniquePaths(vector<vector<int>>& grid, int m, int n, int r, int c){
        if (r == m - 1 && c == n - 1) return 1;
        if(grid[r][c] != 0) return grid[r][c];

        int paths = 0;
        if(inbound(m, n, r+1, c)) paths += findUniquePaths(grid, m, n, r+1, c);
        if(inbound(m, n, r, c+1)) paths += findUniquePaths(grid, m, n, r, c+1);

        grid[r][c] = paths;
        return paths;
    }

    bool inbound(int m, int n, int r, int c) {
        return (r >= 0 && c >= 0 && r < m && c < n);
    }
};