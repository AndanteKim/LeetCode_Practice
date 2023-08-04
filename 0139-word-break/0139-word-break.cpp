class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        unordered_set<int> seen;
        queue<int> queue{{0}};
        
        while (!queue.empty()){
            int start = queue.front();
            queue.pop();
            if (start == s.size()) return true;
            
            for (int end = start + 1; end <= s.size(); ++end){
                if (seen.find(end) != seen.end()) continue;
                if (words.find(s.substr(start, end - start)) != words.end()){
                    queue.push(end);
                    seen.insert(end);
                }
            }
        }
        
        return false;
    }
};