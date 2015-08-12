class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newLength=0;
		int size=nums.size();
		if(size==0)
			return newLength;
		int key=nums[0];
		int keyNum=1;
		newLength=1;
		for(int i=1;i<size;i++){
			if(nums[i]==key)
				keyNum++;
			else{
				key=nums[i];
				keyNum=1;
			}
			if(keyNum<=2){
				nums[newLength]=nums[i];
				newLength++;
			}
		}
		return newLength;
    }
};