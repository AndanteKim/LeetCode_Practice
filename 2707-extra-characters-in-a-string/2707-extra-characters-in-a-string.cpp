class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class Solution {
private:
    TrieNode* buildTrie(vector<string>& dictionary){
        TrieNode* root = new TrieNode();
        for (string& word : dictionary){
            TrieNode* node = root;
            for (char& c : word){
                if (node -> children.find(c) == node -> children.end())
                    node -> children[c] = new TrieNode();
                node = node -> children[c];
            }
            
            node -> isWord = true;
        }
        
        return root;
    }
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        TrieNode* root = buildTrie(dictionary);
        unordered_map<int, int> memo;
        
        function<int(int)> dp = [&](int start){
            if (start == n) return 0;
            if (memo.count(start)) return memo[start];
            
            // To count this character as a left over character
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            TrieNode* node = root;
            for (int end = start; end < n; ++end){
                char c = s[end];
                if (node -> children.find(c) == node -> children.end()) break;
                node = node -> children[c];
                if (node -> isWord) ans = min(ans, dp(end + 1));
            }
            return memo[start] = ans;
        };
        
        return dp(0);
    }
};