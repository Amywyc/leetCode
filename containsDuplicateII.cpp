class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int> mapkv;
		int size=nums.size();
		for(int i=0;i<size;i++){
			if(mapkv.find(nums[i])==mapkv.end())
				mapkv[nums[i]]=i;
			else{
				if(i-mapkv[nums[i]]<=k)
					return true;
				else
					mapkv[nums[i]]=i;
			}
		}
		return false;
    }
};