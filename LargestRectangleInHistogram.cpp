class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int length=height.size();
		if(length<=0)
			return 0;
		stack<int> sta;
		vector<int> pos(length,0);
		for(int i=0;i<length;i++){
			while((!sta.empty())&&(height[sta.top()])>=height[i])
				sta.pop();
			pos[i]=(sta.empty())?-1:sta.top();
			sta.push(i);
		}
		while(!sta.empty())
			sta.pop();
		for(int i=length-1;i>=0;i--){
			while((!sta.empty())&&(height[sta.top()])>=height[i])
				sta.pop();
			pos[i]=(sta.empty())?(length-pos[i]-1):(sta.top()-pos[i]-1);
			sta.push(i);
		}
		int max=0;
		for(int i=0;i<length;i++)
			if(max<pos[i]*height[i])
				max=pos[i]*height[i];
		return max;
    }
};