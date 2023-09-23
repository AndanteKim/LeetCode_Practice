class Solution {
private:
    int dfs(unordered_set<string>& words, unordered_map<string, int>& memo, string& currWord){
        if (memo.find(currWord) != memo.end())
            return memo[currWord];
        
        int maxLength = 1;
        for (int i = 0; i < currWord.size(); ++i){
            string newWord = currWord.substr(0, i) + currWord.substr(i + 1);
            if (words.find(newWord) != words.end()){
                maxLength = max(maxLength, 1 + dfs(words, memo, newWord));
            }
        }
        
        return memo[currWord] = maxLength;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> memo;
        unordered_set<string> wordsPresent;
        
        for (string& word : words){
            wordsPresent.insert(word);
        }
        
        int ans = 0;
        for (string& word : words){
            ans = max(ans, dfs(wordsPresent, memo, word));
        }
        return ans;
    }
};