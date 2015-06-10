class Solution {
public:
	void restoreIpAddresses(int index,int ipNum,
		string& str,string& work,vector<string>& ret){
			int size=str.size();
			if(ipNum>4)
				return ;
			if(index==size){
				if(ipNum==4){
					ret.push_back(work);
					ret[ret.size()-1].pop_back();
				}
				return ;
			}
			int ipTmp=0;
			for(int i=0;i<3;i++){
				if(index+i>=size)
					break;
				ipTmp=ipTmp*10+str[index+i]-'0';
				if((size-1-index-i)<=3*(3-ipNum)){
				    if((i!=0)&&(str[index]=='0'))
						break ;
					if((i==2)&&(ipTmp>255))
						continue;
					for(int j=0;j<=i;j++)
						work.push_back(str[index+j]);
					work.push_back('.');
					restoreIpAddresses(index+i+1,ipNum+1,str,work,ret);
					for(int j=0;j<=i+1;j++)
						work.pop_back();
				}
			}
	}
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
		if(s.size()>0){
			string work;
			restoreIpAddresses(0,0,s,work,ret);
		}
		return ret;
    }
};