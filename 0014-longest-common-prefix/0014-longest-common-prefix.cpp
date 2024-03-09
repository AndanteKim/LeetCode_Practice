class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;

    TrieNode(){}
};

class Trie{
private:
    TrieNode* root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string& word){
        TrieNode* curr = root;
        for (char& c:word){
            if (curr -> children.find(c) == curr -> children.end()){
                curr -> children[c] = new TrieNode();
            }
            curr = curr -> children[c];
        }
        
        curr -> isEnd = true;
    }
    
    string startswith(string& word){
        TrieNode* curr = root;
        string prefix = "";
        
        for (char& c:word){
            if (curr -> isEnd || curr -> children.size() != 1 || curr -> children.find(c) == curr -> children.end()) break;
            curr = curr -> children[c];
            prefix.push_back(c);
        }
        
        return prefix;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        if (strs.size() == 1) return strs[0];
        
        Trie *trie = new Trie();
        
        for (int i = 0; i < strs.size(); ++i)
            trie -> insert(strs[i]);
        
        return trie -> startswith(strs[0]);
    }
};