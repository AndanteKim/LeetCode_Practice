class Trie{
private:
    struct TrieNode{
        int prefixLength = 0;
        unordered_map<char, TrieNode*> children;
    };
    TrieNode* root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& s){
        TrieNode* curr = root;
        
        for (const char& c : s){
            if (!curr -> children.count(c))
                curr -> children[c] = new TrieNode();
            curr = curr -> children[c];
            ++curr -> prefixLength;
        }
    }
    
    int search(const string& s){
        TrieNode* curr = root;
        int prefixSum = 0;
        for (const char& c : s){
            if (!curr -> children.count(c))
                break;
            curr = curr -> children[c];
            prefixSum += curr -> prefixLength;
        }
        
        return prefixSum;
    }
};




class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        Trie* trie = new Trie();
        
        for (string& word : words)
            trie -> insert(word);
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            ans[i] = trie -> search(words[i]);
        }
        return ans;
    }
};