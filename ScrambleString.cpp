class Solution {
public:
    bool isScramble(string s1, string s2) {
		if((s1.size()==0)&&(s2.size()==0))
			return true;
		if(s1.size()!=s2.size())
			return false;
		int len=s1.size();
		vector<vector<vector<bool>>> dp
			(len,vector<vector<bool>>(len,vector<bool>(len+1,false)));
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				if(s1[i]==s2[j])
					dp[i][j][1]=true;
		for(int n=2;n<=len;n++)
			for(int i=0;i<len-n+1;i++)
				for(int j=0;j<len-n+1;j++)
					for(int k=1;k<n;k++){
						dp[i][j][n]=(dp[i][j][k]&&dp[i+k][j+k][n-k])||(dp[i][j][n]);
						dp[i][j][n]=(dp[i][j+n-k][k]&&dp[i+k][j][n-k])||(dp[i][j][n]);
					}
		return dp[0][0][len];
    }
};