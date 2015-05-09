class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int m=obstacleGrid.size();
		int n=obstacleGrid[0].size();
		if((m<1)||(n<1))
			return 0;

		if(obstacleGrid[0][0]==1)
			return 0;

		vector<vector<int>> ways(m,vector<int>(n,0));
		ways[0][0]=1;
		for(int i=1;i<m;i++)
			if((obstacleGrid[i][0]==0)&&(ways[i-1][0]==1))
				ways[i][0]=1;
		for(int i=1;i<n;i++)
			if((obstacleGrid[0][i]==0)&&(ways[0][i-1]==1))
				ways[0][i]=1;
		for(int i=1;i<m;i++)
			for(int j=1;j<n;j++)
				if(obstacleGrid[i][j]==0)
					ways[i][j]=ways[i-1][j]+ways[i][j-1];
		return ways[m-1][n-1];
		
    }
};