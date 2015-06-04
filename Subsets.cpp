class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int size=nums.size();
		int tmpSize;
		sort(nums.begin(),nums.end());
		vector<vector<int>> res;
		res.push_back(vector<int>());
		for(int i=0;i<size;i++){
			tmpSize=res.size();
			for(int j=0;j<tmpSize;j++){
				vector<int> tmp(res[j]);
				tmp.push_back(nums[i]);
				res.push_back(tmp);
			}
		}
		return res;
    }
};