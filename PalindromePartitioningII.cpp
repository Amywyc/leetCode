class Solution {
public:
    int minCut(string s) {
        int len=s.size();
		if(len<=1)
			return 0;

		vector<vector<bool>> dp(len+1,vector<bool>(len+1,false));
		for(int i=0;i<len;i++)
			dp[i][i]=dp[i+1][i]=true;
		for(int d=1;d<len;d++)
			for(int i=0,j=i+d;j<len;i++,j++)
				if(s[i]==s[j])
					dp[i][j] = dp[i+1][j-1];

		vector<int> cut(len+1,0);
		for(int i=0;i<=len;i++)
			cut[i]=i-1;
		for(int i=2;i<=len;i++)
			if(dp[0][i-1])
				cut[i]=0;
			else
				for(int j=1;j<=i;j++)
					if(dp[j-1][i-1])
						cut[i]=min(cut[i],cut[j-1]+1);
		return cut[len];
    }
};