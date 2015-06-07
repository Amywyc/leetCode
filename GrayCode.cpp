class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
		ret.push_back(0);
		if(n>0){
			ret.push_back(1);
			int base,tmpSize;
			for(int i=1;i<n;i++){
				base=1<<i;
				tmpSize=ret.size();
				for(int j=tmpSize-1;j>=0;j--)
					ret.push_back(base+ret[j]);
			}
		}
		return ret;
    }
};
