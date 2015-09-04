class Solution {
public:
	bool findSequence(vector<int>& nums,int start,int end,int target){
		if(start>end)
			return false;
		for(int i=start;i<=end;i++)
			if(nums[i]==target)
				return true;
		return false;
	}
    bool search(vector<int>& nums, int target) {
        int size=nums.size();
		if(size<=0)
			return -1;
		int low=0,high=size-1,mid;
		while(low<high-1){
			mid=low+(high-low)/2;
			if(nums[mid]==target)
				return true;
			else{
				if((nums[low]==nums[high])&&(nums[low]==nums[mid]))
					return findSequence(nums,low,high,target);
				if(nums[mid]>=nums[low]){
					if(nums[mid]>target){
						(nums[low]<=target)?high=mid:low=mid;
					}else{
						low=mid;
					}
				}else if(nums[mid]<=nums[high]){
					if(nums[mid]>target){
						high=mid;
					}else{
						(nums[high]>=target)?low=mid:high=mid;
					}
				}
			}
		}
		if((nums[low]==target)||(nums[high]==target))
			return true;
		else
			return false;
    }
};