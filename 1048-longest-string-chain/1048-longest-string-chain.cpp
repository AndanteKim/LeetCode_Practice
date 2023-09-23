class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [](const string& w1, const string& w2){return w1.size() < w2.size();});
        
        int ans = 1;
        
        for (const string& word : words){
            int currLength = 1;
            
            for (int i = 0; i < word.size(); ++i){
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(predecessor) != dp.end()){
                    int prevLength = dp[predecessor];
                    currLength = max(currLength, prevLength + 1);
                }
            }
            dp[word] = currLength;
            ans = max(ans, currLength);
        }
        
        return ans;
    }
};