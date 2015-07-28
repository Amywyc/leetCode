class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
		if(size<=0)
			return false;
		int step=nums[0];
		for(int i=1;i<size;i++){
			if(step>=(size-i))
				return true;
			if(step>0){
				step--;
				if(nums[i]>step)
					step=nums[i];
			}else
				return false;
		}
		return true;
    }
};