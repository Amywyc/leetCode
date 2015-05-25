class Solution {
public:
    int numDistinct(string s, string t) {
        int s_len=s.size();
		int t_len=t.size();
		vector<vector<int>> dp(t_len+1,vector<int>(s_len+1,0));
		for(int i=0;i<=s_len;i++)
			dp[0][i]=1;
		for(int i=1;i<=t_len;i++)
			for(int j=i;j<=s_len;j++){
				dp[i][j]=((s[j-1]==t[i-1])?dp[i-1][j-1]:0)+dp[i][j-1];
			}
		return dp[t_len][s_len];
    }
};