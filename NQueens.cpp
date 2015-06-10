class Solution {
public:
	void solveAdd(vector<int>& work,vector<vector<string>>& ret){
		string tmp;
		int size=work.size();
		ret.push_back(vector<string>(size,string(size,'.')));
		int tmpSize=ret.size();
		for(int i=0;i<size;i++){
			ret[tmpSize-1][i][work[i]]='Q';
		}
	}
	void swp(vector<int>& work,int index1,int index2){
		int tmp=work[index1];
		work[index1]=work[index2];
		work[index2]=tmp;
	}
	void solveNQueens_aux(int index,
		vector<int>& work,vector<vector<string>>& ret,
		vector<int>& sum,vector<int>& sub){
			int size=work.size();
			if(index==work.size()){
				solveAdd(work,ret);
				return ;
			}
			for(int i=index;i<size;i++){
				if((!sum[index+work[i]])&&(!sub[index-work[i]+size-1])){
					sum[index+work[i]]=1;
					sub[index-work[i]+size-1]=1;
					swp(work,i,index);
					solveNQueens_aux(index+1,work,ret,sum,sub);
					swp(work,index,i);
					sum[index+work[i]]=0;
					sub[index-work[i]+size-1]=0;
				}
			}
	}
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> ret;
		if(n>0){
			vector<int> work(n);
			for(int i=0;i<n;i++)
				work[i]=i;
			vector<int> sum(2*n-1,0);
			vector<int> sub(2*n-1,0);
			solveNQueens_aux(0,work,ret,sum,sub);
		}
		return ret;
    }
};