class Solution {
public:
	void swap(vector<int>& nums,int pos1,int pos2){
		int tmp=nums[pos1];
		nums[pos1]=nums[pos2];
		nums[pos2]=tmp;
	}
	void permute_aux(int index,vector<int>& nums,
		vector<vector<int>>& ret){
		int size=nums.size();
		if(index==size-1){
			ret.push_back(nums);
			return ;
		}
		for(int i=index;i<size;i++){
			swap(nums,index,i);
			permute_aux(index+1,nums,ret);
			swap(nums,i,index);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
		if(nums.size()>0){
			permute_aux(0,nums,ret);
		}
		return ret;
    }
};