class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		vector<int> ret;
		int size=nums.size();
        int num1,num2,time1=0,time2=0;
		for(int i=0;i<size;i++){
			 if((time1!=0)&&(num1==nums[i])){
				time1++;
			}else if((time2!=0)&&(num2==nums[i])){
				time2++;
			}else if(time1==0){
				time1=1;
				num1=nums[i];
			}else if(time2==0){
				time2=1;
				num2=nums[i];
			}else{
				time1--;
				time2--;
			}
		}
		int count1=0,count2=0;
		for(int i=0;i<size;i++){
			if((time1>0)&&(nums[i]==num1))
				count1++;
			if((time2>0)&&(nums[i]==num2))
				count2++;
		}
		if(count1>size/3)
			ret.push_back(num1);
		if(count2>size/3)
			ret.push_back(num2);
		return ret;
    }
};