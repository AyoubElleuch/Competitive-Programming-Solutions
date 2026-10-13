class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);

        return findNumTrees(n, dp);
    }

    int findNumTrees(int n, vector<int>& dp){
        if(n==0 || n==1) return 1;
        if(dp[n] > 0) return dp[n];

        int total = 0;
        for(int i=1; i<=n; i++){
            int left = findNumTrees(i-1, dp);
            int right = findNumTrees(n-i, dp);
            total += left * right;
        }

        dp[n] = total;
        return dp[n];
    }
};