class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int length1=s1.size();
		int length2=s2.size();
		int length3=s3.size();
		if((length1+length2)!=length3)
			return false;
		vector<vector<int>> dp(length1+1,vector<int>(length2+1,0));
		dp[0][0]=1;
		for(int i=0;i<=length1;i++)
			for(int j=0;j<=length2;j++){
				if((i!=0)&&(dp[i-1][j]==1)&&(s1[i-1]==s3[i+j-1]))
					dp[i][j]=1;
				if((j!=0)&&(dp[i][j-1]==1)&&(s2[j-1]==s3[i+j-1]))
					dp[i][j]=1;
			}
		return dp[length1][length2];
    }
};