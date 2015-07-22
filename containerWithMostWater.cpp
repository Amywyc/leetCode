class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
		int low=0;
		int high=height.size()-1;
		int nowArea;
		while(low<high){
			nowArea=(high-low)*((height[high]<height[low])?height[high]:height[low]);
			if(nowArea>max)
				max=nowArea;
			if(height[low]<height[high])
				low++;
			else
				high--;
		}
		return max;
    }
};