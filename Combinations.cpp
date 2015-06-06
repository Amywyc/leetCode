class Solution {
public:
	void combine_aux(int n,int k,int index,
		vector<int>& work,vector<vector<int>>& ret){
		if(k==0){
			ret.push_back(work);
			return ;
		}
		for(int i=index;i<=n;i++){
			work.push_back(i);
			combine_aux(n,k-1,i+1,work,ret);
			work.pop_back();
		}
	}
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
		if((n>0)&&(k>0)&&(k<=n)){
			vector<int> work;
			combine_aux(n,k,1,work,ret);
		}
		return ret; 
    }
};