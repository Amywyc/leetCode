class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int size=nums.size();
		int tmpSize;
		int tmpCount=0;
		sort(nums.begin(),nums.end());
		vector<vector<int>> res;
		res.push_back(vector<int>());
		for(int i=0;i<size;i++){
			if((i<size-1)&&(nums[i+1]==nums[i])){
				tmpCount++;
				continue;
			}
			tmpSize=res.size();
			for(int j=0;j<tmpSize;j++){
				vector<int> tmp(res[j]);
				for(int k=0;k<=tmpCount;k++){
					tmp.push_back(nums[i]);
					res.push_back(tmp);
				}
			}
			tmpCount=0;
		}
		return res;
    }
};