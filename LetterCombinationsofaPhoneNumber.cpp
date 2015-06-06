class Solution {
public:
	void letterCombinations_aux(vector<string>& phoneNum,string& digits,int index,
		string& work,vector<string>& ret){
		if(index==digits.size()){
			ret.push_back(work);
			return ;
		}
		if((digits[index]<'0')||(digits[index]>'9'))
			return ;
		int num=digits[index]-'0';
		for(int i=0;i<phoneNum[num].size();i++){
			work.push_back(phoneNum[num][i]);
			letterCombinations_aux(phoneNum,digits,index+1,work,ret);
			work.pop_back();
		}
	}
    vector<string> letterCombinations(string digits) {
        string phone[]={"",
			"","abc","def",
			"ghi","jkl","mno",
			"pqrs","tuv","wxyz"};
		vector<string> phoneNum(phone,phone+10);
		vector<string> ret;
		string work;
		if(digits.size()>0)
			letterCombinations_aux(phoneNum,digits,0,work,ret);
		return ret;
    }
};