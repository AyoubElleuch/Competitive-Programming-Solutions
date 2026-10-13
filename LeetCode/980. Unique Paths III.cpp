class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // find starting, ending, and number of empty cells
        pair<int, int> start, end;
        int empty = 1;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1) start = {i, j};
                else if(grid[i][j] == 2) end = {i, j};
                else if(grid[i][j] == 0) empty++;
            }
        }

        return findUniquePaths(grid, visited, m, n, end, empty, start.first, start.second);
    }

    int findUniquePaths(vector<vector<int>>& grid, vector<vector<bool>>& visited, int m, int n, pair<int, int>& end, int empty, int r, int c){
        if(grid[r][c] == -1 || visited[r][c]) return 0;
        if(r == end.first && c == end.second){
            if(empty == 0) return 1;
            return 0;
        }
        int paths = 0;
        visited[r][c] = true;
        if(inbound(m, n, r-1, c)) paths += findUniquePaths(grid, visited, m, n, end, empty - 1, r-1, c);
        if(inbound(m, n, r+1, c)) paths += findUniquePaths(grid, visited, m, n, end, empty - 1, r+1, c);
        if(inbound(m, n, r, c-1)) paths += findUniquePaths(grid, visited, m, n, end, empty - 1, r, c-1);
        if(inbound(m, n, r, c+1)) paths += findUniquePaths(grid, visited, m, n, end, empty - 1, r, c+1);

        visited[r][c] = false;

        return paths;
    }

    bool inbound(int m, int n, int r, int c){
        return (r >= 0 && r < m && c >= 0 && c < n);
    }
};