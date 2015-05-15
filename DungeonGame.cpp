class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
		int n=dungeon[0].size();

		vector<vector<int>> dp(m,vector<int>(n,0));
		int tmpRight,tmpDown;
		for(int i=m-1;i>=0;i--)
			for(int j=n-1;j>=0;j--){
				if((i==m-1)&&(j==n-1))
					dp[i][j]=max(1-dungeon[i][j],1);
				else{
					tmpRight=((j==n-1)?INT_MAX:max(dp[i][j+1]-dungeon[i][j],1));
					tmpDown=((i==m-1)?INT_MAX:max(dp[i+1][j]-dungeon[i][j],1));
					dp[i][j]=min(tmpRight,tmpDown);
				}
			}
		return dp[0][0];
    }
};