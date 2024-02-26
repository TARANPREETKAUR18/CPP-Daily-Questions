class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        int dp[n+1][k+1];
        memset(dp, -1, sizeof(dp));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int i=0;i<=k;i++)dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                int curr=0;
                for(int bd=1;bd<i;bd++){
                    curr=max(curr, dp[bd][j-1]+prices[i-1]-prices[bd-1]);
                    dp[i][j]=max(dp[i][j], curr);
                }
                dp[i][j]=max(dp[i][j], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
};