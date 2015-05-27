class Solution {
public:
    bool isMatch(string s, string p) {
        int len_s=s.size();
		int len_p=p.size();

		int count_char=0;
		for(int i=0;i<len_p;i++)
			if(p[i]!='*')
				count_char++;
		if(count_char>len_s)
			return false;

		vector<int> dp(len_s+1,0);
		int first_match=0;
		dp[first_match]=1;
		for(int i=1;i<=len_p;i++){
			if((i>1)&&(p[i-1]=='*')&&(p[i-2]=='*'))
				continue;
			if(p[i-1]=='*'){
				for(int i=first_match+1;i<=len_s;i++)
					dp[i]=1;
			}else{
				int match_id=-1;
				for(int j=len_s;j>first_match;j--){
					dp[j]=(((p[i-1]=='?')||(p[i-1]==s[j-1]))?dp[j-1]:0);
					if(dp[j])
						match_id=j;
				}
				if(match_id!=-1)
					first_match=match_id;
				else 
					return false;
			}
		}
		return dp[len_s];
    }
};