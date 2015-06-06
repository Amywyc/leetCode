class Solution {
public:
	void combinationSum_aux(vector<int>& candidates,int target,int index,
		vector<int>& work,vector<vector<int>>& ret){
			if(target<0)
				return ;
			if(target==0){
				ret.push_back(work);
				return ;
			}
				
			for(int i=index;i<candidates.size();i++){
				if((i!=index)&&(candidates[i]==candidates[i-1]))
					continue;
				work.push_back(candidates[i]);
				combinationSum_aux(candidates,target-candidates[i],i+1,work,ret);
				work.pop_back();
			}
	}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
		vector<int> work;
		sort(candidates.begin(),candidates.end());
		if(target!=0)
			combinationSum_aux(candidates,target,0,work,ret);
		return ret;
    }
};