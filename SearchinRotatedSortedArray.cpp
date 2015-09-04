class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size();
		if(size<=0)
			return -1;
		int low=0,high=size-1,mid;
		while(low<high-1){
			mid=low+(high-low)/2;
			if(nums[mid]==target)
				return mid;
			else{
				if(nums[mid]>nums[low]){
					if(nums[mid]>target){
						(nums[low]<=target)?high=mid:low=mid;
					}else{
						low=mid;
					}
				}else if(nums[mid]<nums[high]){
					if(nums[mid]>target){
						high=mid;
					}else{
						(nums[high]>=target)?low=mid:high=mid;
					}
				}
			}
		}
		if(nums[low]==target)
			return low;
		else if(nums[high]==target)
			return high;
		else
			return -1;
    }
};