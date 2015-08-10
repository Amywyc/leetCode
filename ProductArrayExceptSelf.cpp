class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
		vector<int> ret(size,1);
		ret[0]=nums[0];
		for(int i=1;i<size;i++){
			ret[i]=ret[i-1]*nums[i];
		}
		for(int i=size-2;i>=0;i--){
			nums[i]=nums[i]*nums[i+1];
		}
		if(size!=1){
			ret[size-1]=ret[size-2];
			for(int i=size-2;i>0;i--)
				ret[i]=ret[i-1]*nums[i+1];
			ret[0]=nums[1];
		}
		return ret;
    }
};