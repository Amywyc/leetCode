class Solution {
public:
	void swp(vector<int>& nums,int index1,int index2){
		int tmp=nums[index1];
		nums[index1]=nums[index2];
		nums[index2]=tmp;
	}
	void getPermutation_aux(int index,int k,vector<int>& permu,
		vector<int>& nums){
			int size=nums.size();
			if(k==0)
				return ;
			if(k==1){
				swp(nums,size-2,size-1);
				return ;
			}
			int leftPos=nums.size()-1-index;
			int mov=k/permu[leftPos-1];
			int left=k%permu[leftPos-1];
			int tmp=nums[index+mov];
			for(int i=index+mov;i>index;i--)
				nums[i]=nums[i-1];
			nums[index]=tmp;
			getPermutation_aux(index+1,left,permu,nums);
	}
    string getPermutation(int n, int k) {
        vector<int> nums(n);
		for(int i=0;i<n;i++)
			nums[i]=i+1;
		vector<int> permu(n);
		permu[0]=1;
		for(int i=1;i<n;i++)
			permu[i]=permu[i-1]*(i+1);
		string ret;
		if((n>0)&&(k>0)&&(k<=permu[n-1])){
			if(k>1)
				getPermutation_aux(0,k-1,permu,nums);
			for(int i=0;i<nums.size();i++)
				ret.push_back('0'+nums[i]);
		}
		return ret;
    }
};