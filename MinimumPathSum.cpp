class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size();
		int n=grid[0].size();
		if((m==0)&&(n==0))
			return 0;

		vector<vector<int>> min(m,vector<int>(n,0));
		min[0][0]=grid[0][0];
		for(int i=1;i<n;i++)
			min[0][i]=min[0][i-1]+grid[0][i];
		for(int j=1;j<m;j++)
			min[j][0]=min[j-1][0]+grid[j][0];
		for(int j=1;j<m;j++)
			for(int i=1;i<n;i++)
				min[j][i]=((min[j-1][i]>min[j][i-1])?min[j][i-1]:min[j-1][i])+grid[j][i];
		return min[m-1][n-1];

    }
};