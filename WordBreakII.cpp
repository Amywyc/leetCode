//BackTracking
class Solution {
public:
	vector<string> wordBreakHelper(string s,unordered_set<string>& wordDict,map<string,vector<string>>& cache){
		if(cache.find(s)!=cache.end())
			return cache[s];

		vector<string> result;
		int size=s.size();
		for(int i=0;i<size;i++){
			string word=s.substr(0,i+1);
			if(wordDict.find(word)!=wordDict.end()){
				if(i==size-1){
					result.push_back(word);
					break;
				}

				vector<string> ret=wordBreakHelper(s.substr(i+1,size-i-1),wordDict,cache);
				for(int j=0;j<ret.size();j++)
					result.push_back(word+" "+ret[j]);
			}
		}
		cache[s]=result;
		return result;
	}

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        
		int size=s.size();
		vector<string> ret;
		if(size<=0)
			return ret;

		map<string,vector<string>> cache;
		return wordBreakHelper(s,wordDict,cache);
		
    }
};
//DynamicProgramming
