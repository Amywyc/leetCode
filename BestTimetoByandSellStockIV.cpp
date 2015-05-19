class Solution {
public:
    int maxProfitAnyTime(vector<int>& prices){
		int sum=0;
		for(int i=1;i<prices.size();i++)
			if(prices[i]-prices[i-1]>0)
				sum += prices[i]-prices[i-1];
		return sum;
	}
    int maxProfit(int k, vector<int>& prices) {
       int nday=prices.size();
	   if(nday<=0)
		   return 0;
	   int diff;
	   if(k>nday)
		   return maxProfitAnyTime(prices);
	   vector<int> local(k+1,0);
	   vector<int> global(k+1,0);
	   for(int i=1;i<nday;i++){
		   diff=prices[i]-prices[i-1];
		   for(int j=k;j>=1;j--){
				local[j]=max(local[j]+diff,global[j-1]+max(0,diff));
				global[j]=max(global[j],local[j]);
		   }
	   }
	   return global[k];
    }
};