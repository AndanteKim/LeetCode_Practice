class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        vector<bool> seen(s.size(), false);
        for (string& word : wordDict) words.insert(word);
        
        queue<int> queue{{0}};
        
        while (!queue.empty()){
            int i = queue.front();
            queue.pop();
            if (i == s.size()) return true;
            
            for (int end = i + 1; end <= s.size(); ++end){
                if (seen[end]) continue;
                if (words.find(s.substr(i, end - i)) != words.end()){
                    seen[end] = true;
                    queue.push(end);
                }
            }
        }
        
        return false;
    }
};