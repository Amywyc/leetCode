class Solution1 {
public:
    int longestValidParentheses(string s) {
        int length=s.size();
		vector<int> parentLength(length,0);
		stack<int> leftStack;
		int max=0,leftIndex;
		for(int i=0;i<length;i++){
			if(s[i]=='('){
				leftStack.push(i);
			}else{
				if(!leftStack.empty()){
					leftIndex=leftStack.top();
					leftStack.pop();
					parentLength[i]+=i-leftIndex+1;
					if(leftIndex!=0)
						parentLength[i]+=parentLength[leftIndex-1];
					if(parentLength[i]>max)
						max=parentLength[i];
				}
			}
		}
		return max;
    }
};     
//better
class Solution2 {
public:
    int longestValidParentheses(string s) {
		int length=s.size();
		int max=0,sum;

		int leftCount=0;
		sum=0;
		for(int i=0;i<length;i++){
			if(s[i]=='('){
				leftCount+=1;
				sum+=1;
			}else{
				sum+=-1;
			}
			if(sum<0){
				leftCount=0;
				sum=0;
			}else if(sum==0){
				if(max<leftCount)
					max=leftCount;
			}
		}

		int rightCount=0;
		sum=0;
		for(int i=length-1;i>=0;i--){
			if(s[i]==')'){
				rightCount+=1;
				sum+=1;
			}else{
				sum+=-1;
			}
			if(sum<0){
				rightCount=0;
				sum=0;
			}else if(sum==0){
				if(max<rightCount)
					max=rightCount;
			}
		}
			
		return 2*max;
    }
};