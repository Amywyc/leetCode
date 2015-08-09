class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size();
		if(size<=1)
			return ;
		int tmp;
		int pos1=size-2;
		while((pos1>=0)&&(nums[pos1]>=nums[pos1+1]))
			pos1--;
		if(pos1!=-1){
			int pos2=size-1;
			while((pos2>pos1)&&(nums[pos2]<=nums[pos1]))
				pos2-- ;
			tmp=nums[pos1];
			nums[pos1]=nums[pos2];
			nums[pos2]=tmp;
		}
		for(int i=pos1+1;i<=(pos1+size)/2;i++){
			tmp=nums[i];
			nums[i]=nums[pos1+size-i];
			nums[pos1+size-i]=tmp;
		}
		return ;
    }
};