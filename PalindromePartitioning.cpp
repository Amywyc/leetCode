class Solution {
public:
    bool isPalindrome(string& s,int start,int end){
		for(;start<end;start++,end--)
			if(s[start]!=s[end])
				return false;
		return true;
	}
	void helper(string& str,int index,vector<string>& tmpVector,vector<vector<string>>& cache){
		if(index==str.size())
			cache.push_back(tmpVector);
		else
			for(int i=index;i<str.size();i++){
				if(isPalindrome(str,index,i)){
					tmpVector.push_back(str.substr(index,i-index+1));
					helper(str,i+1,tmpVector,cache);
					tmpVector.pop_back();
				}
			}
	}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> cache;
		vector<string> tmpVector;
		int len=s.size();
		if(len<=0)
			return cache;
		helper(s,0,tmpVector,cache);
		return cache;
    }
};