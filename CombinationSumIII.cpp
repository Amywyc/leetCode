class Solution {
public:
	void combinationSum3_aux(int k,int n,int index,
		vector<int>& work,vector<vector<int>>& ret){
		if((k<0)||(n<0))
			return ;
		if((k==0)&&(n==0)){
			ret.push_back(work);
			return ;
		}
		for(int i=index;i<=9;i++){
			work.push_back(i);
			combinationSum3_aux(k-1,n-i,i+1,work,ret);
			work.pop_back();
		}
	}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
		if((n>=1)&&(n<=45)&&(k>=1)&&(k<=9)){
			vector<int> work;
			combinationSum3_aux(k,n,1,work,ret);
		}
		return ret;
    }
};