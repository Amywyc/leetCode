class Solution {
public:
    int numDecodings(string s) {
        
        int size=s.size();
		if((size<=0)||(s[0]=='0'))
			return 0;

		vector<int> f1(size,0);
		vector<int> f2(size,0);
		if(size>=1){
			f1[0]=1;
			f2[0]=0;
		}
		for(int i=1;i<size;i++){
			if(s[i]=='0'){
				f1[i]=0;
				if((s[i-1]=='1')||(s[i-1]=='2'))
					f2[i]=f1[i-1];
				else
					return 0;
			}else{
				f1[i]=f1[i-1]+f2[i-1];
				if((s[i-1]=='1')&&(s[i]>='1')&&(s[i]<='9'))
					f2[i]=f1[i-1];
				else if((s[i-1]=='2')&&(s[i]>='1')&&(s[i]<='6'))
					f2[i]=f1[i-1];
				else
					f2[i]=0;
			}
		}
		return f1[size-1]+f2[size-1];

    }
};