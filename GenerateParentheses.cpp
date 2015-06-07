class Solution {
public:
	void generateParenthesis_aux(int pos,int sum,
		string& work,vector<string>& ret){
		if((pos<0)||(sum<0))
			return ;
		if((pos==0)&&(sum==0)){
			ret.push_back(work);
			return ;
		}
		work.push_back('(');
		generateParenthesis_aux(pos-1,sum+1,work,ret);
		work.pop_back();
		work.push_back(')');
		generateParenthesis_aux(pos-1,sum-1,work,ret);
		work.pop_back();
	}
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
		if(n>0){
			string work;
			generateParenthesis_aux(2*n,0,work,ret);
		}
		return ret;
    }
};