#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {

		if(n<=0)
			return 0;

        vector<int> method(n,0);
		if(n>=1)
			method[0]=1;
		if(n>=2)
			method[1]=2;
		for(int i=2;i<n;i++)
			method[i]=method[i-2]+method[i-1];
		return method[n-1];
    }
};

int main(){
	Solution s;
	cout<<s.climbStairs(10)<<endl;
	return 0;
}