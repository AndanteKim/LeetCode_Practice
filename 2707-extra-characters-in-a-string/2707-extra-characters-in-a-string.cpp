class TrieNode{
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
};


class Solution {
private:
    TrieNode* buildTrie(vector<string>& dictionary){
        TrieNode* node = new TrieNode();
        for (string& word : dictionary){
            TrieNode* curr = node;
            for (char& c : word){
                if (curr -> children.find(c) == curr -> children.end()){
                    curr -> children[c] = new TrieNode();
                }
                curr = curr -> children[c];
            }
            curr -> isWord = true;
        }
        return node;
    }
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        TrieNode* root = buildTrie(dictionary);
        vector<int> dp(n + 1);
        
        for (int start = n - 1; start >= 0; --start){
            dp[start] = dp[start + 1] + 1;
            TrieNode* node = root;
            for (int end = start; end < n; ++end){
                if (node -> children.find(s[end]) == node -> children.end()) break;
                node = node -> children[s[end]];
                if (node -> isWord) dp[start] = min(dp[start], dp[end + 1]);
            }
        }
        
        return dp[0];
    }
};