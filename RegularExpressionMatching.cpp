class Solution {
public:
	bool helper(string& s,string& p,int index_s,int index_p){
		if(index_p==p.size())
			return (index_s==s.size());

		if(p[index_p]=='*')
			return false;

		if((index_p==p.size()-1)||(p[index_p+1]!='*')){
			if((s[index_s]==p[index_p])||(p[index_p]=='.'))
				return helper(s,p,index_s+1,index_p+1);
			else
				return false;
		}else{
			while((index_s<s.size())&&(s[index_s]==p[index_p]||(p[index_p]=='.'))){
				if(helper(s,p,index_s,index_p+2))
					return true;
				index_s++;
			}
			return helper(s,p,index_s,index_p+2);
		}	
	}
    bool isMatch(string s, string p) {
        return helper(s,p,0,0);
    }
};