class Solution {
public:
	void swp(vector<int>& work,int index1,int index2){
		int tmp=work[index1];
		work[index1]=work[index2];
		work[index2]=tmp;
	}
	void totalNQueens_aux(int index,
		vector<int>& work,int& totalNum,
		vector<int>& sum,vector<int>& sub){
			int size=work.size();
			if(index==work.size()){
				totalNum++;
				return ;
			}
			for(int i=index;i<size;i++){
				if((!sum[index+work[i]])&&(!sub[index-work[i]+size-1])){
					sum[index+work[i]]=1;
					sub[index-work[i]+size-1]=1;
					swp(work,i,index);
					totalNQueens_aux(index+1,work,totalNum,sum,sub);
					swp(work,index,i);
					sum[index+work[i]]=0;
					sub[index-work[i]+size-1]=0;
				}
			}
	}
    int totalNQueens(int n) {
        int totalNum=0;
		if(n>0){
			vector<int> work(n);
			for(int i=0;i<n;i++)
				work[i]=i;
			vector<int> sum(2*n-1,0);
			vector<int> sub(2*n-1,0);
			totalNQueens_aux(0,work,totalNum,sum,sub);
		}
		return totalNum;
    }
};