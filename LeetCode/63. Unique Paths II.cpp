class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> grid(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();


        return findUniquePaths(grid, obstacleGrid, m, n, m-1, n-1);
    }

    int findUniquePaths(vector<vector<int>>& grid, vector<vector<int>>& obstacleGrid, int m, int n, int r, int c){
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == 0 && c == 0) return 1;
        if(grid[r][c] != -1) return grid[r][c];

        int possiblePaths = 0;
        if(inbound(m, n, r-1, c)) possiblePaths += findUniquePaths(grid, obstacleGrid, m, n, r-1, c);
        if(inbound(m, n, r, c-1)) possiblePaths += findUniquePaths(grid, obstacleGrid, m, n, r, c-1);

        grid[r][c] = possiblePaths;
        return possiblePaths;
    }

    bool inbound(int m, int n, int r, int c){
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
};