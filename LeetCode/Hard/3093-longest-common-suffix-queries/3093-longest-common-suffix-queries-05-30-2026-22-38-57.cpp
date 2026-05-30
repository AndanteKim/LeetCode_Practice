struct TrieNode {
    int shortestLen;
    int index;
    unordered_map<char, TrieNode*> children;
    
    TrieNode() : shortestLen(std::numeric_limits<int>::max()), index(-1) {}
};

class Trie {
private:
    TrieNode* root;

    void deleteNodes(TrieNode* node) {
        if (!node) return;
        for (auto& p : node -> children) deleteNodes(p.second);
        delete(node);
    }
    
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteNodes(root);
    }
    
    void insert(string word, int idx) {
        TrieNode* curr = root;
        int n = word.length();
        
        if (n < curr->shortestLen) {
            curr->index = idx;
            curr->shortestLen = n;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                curr->children[word[i]] = new TrieNode();
            }
            curr = curr->children[word[i]];
            if (n < curr->shortestLen) {
                curr->shortestLen = n;
                curr->index = idx;
            }
        }
    }
    
    int search(string word) {
        TrieNode* curr = root;
        int n = word.length();
        
        for (int i = n - 1; i >= 0; i--) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                return curr->index;
            }
            curr = curr->children[word[i]];
        }
        
        return curr->index;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie trie;
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            trie.insert(wordsContainer[i], i);
        }
        
        vector<int> ans(wordsQuery.size());
        
        for (int i = 0; i < wordsQuery.size(); i++) {
            ans[i] = trie.search(wordsQuery[i]);
        }
        
        return ans;
    }
};