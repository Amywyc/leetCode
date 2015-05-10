class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {

		int size=s.size();
		if(size<=0)
			return true;

		vector<bool> word(size,false);
		for(int i=0;i<size;i++){
			word[i]=(wordDict.find(s.substr(0,i+1))!=wordDict.end());
			if(!word[i])
				for(int j=0;j<i;j++)
					if(word[j]){
						word[i]=(wordDict.find(s.substr(j+1,i-j))!=wordDict.end());
						if(word[i])
							break;
					}
		}
		return word[size-1];
    }
};