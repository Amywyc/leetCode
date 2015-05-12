//space O(n*n)
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        
        int size=triangle.size();
		if(size<=0)
			return 0;

		for(int i=1;i<size;i++)
			for(int j=0;j<=i;j++){
				if(j==0)
					triangle[i][0]=triangle[i-1][0]+triangle[i][0];
				else if(j==i)
					triangle[i][i]=triangle[i-1][i-1]+triangle[i][i];
				else
					triangle[i][j]=((triangle[i-1][j-1]>triangle[i-1][j])?
						triangle[i-1][j]:triangle[i-1][j-1])+triangle[i][j];
			}
		int min=triangle[size-1][0];
		for(int i=1;i<size;i++)
			if(min>triangle[size-1][i])
				min=triangle[size-1][i];
		return min;
		
    }
};

//space O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size=triangle.size();
		if(size<=0)
			return 0;

		vector<int> tmpTotal(2*size,0);
		tmpTotal[0]=triangle[0][0];
		int flage1=1,flage2=0;
		for(int i=1;i<size;i++){
			flage1 ^= 1;
			flage2 ^= 1;
			for(int j=0;j<=i;j++){
				if(j==0)
					tmpTotal[flage2*size]=tmpTotal[flage1*size]+triangle[i][0];
				else if(j==i)
					tmpTotal[flage2*size+i]=tmpTotal[flage1*size+i-1]+triangle[i][i];
				else
					tmpTotal[flage2*size+j]=((tmpTotal[flage1*size+j-1]>tmpTotal[flage1*size+j])?
						tmpTotal[flage1*size+j]:tmpTotal[flage1*size+j-1])+triangle[i][j];
			}
		}
		int start,end;
		if((size%2)==1){
			start=0;
			end=size;
		}else{
			start=size;
			end=2*size;
		}
		int min=tmpTotal[start];
		for(int i=start+1;i<end;i++)
			if(min>tmpTotal[i])
				min=tmpTotal[i];
		return min;
    }
};
//learn
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		int level = triangle.size();
		vector<int> dp(level + 1, 0);
		for (int i = level - 1;i >= 0; i--){
			for (int j = 0; j <= i; j++)
				dp[j] = triangle[i][j] + ((dp[j]>dp[j+1])?dp[j+1]:dp[j]);
		}
		return dp[0];
    }
};
