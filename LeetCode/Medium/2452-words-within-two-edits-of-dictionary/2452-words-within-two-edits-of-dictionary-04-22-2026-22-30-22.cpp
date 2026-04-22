class Solution {
private:
    struct TrieNode {
        vector<TrieNode*> children;
        bool isEnd;
        TrieNode(): isEnd(false) {
            children.resize(26, nullptr);
        }
    };
    TrieNode* root = new TrieNode();

    void insert(const string& word) {
        TrieNode* node = root;
        for (const char& c : word) {
            int idx = c - 'a';
            
            if (!node -> children[idx]) 
                node -> children[idx] = new TrieNode();
            
            node = node -> children[idx];
        }

        node -> isEnd = true;
    }

    bool dfs(int i, const string& word, TrieNode* node, int cnt) {
        if (cnt > 2 || !node) return false;

        if (i == word.size()) return node -> isEnd;

        int idx = word[i] - 'a';

        // No changes made
        if (node -> children[idx] && dfs(i + 1, word, node -> children[idx], cnt)) return true;

        // Made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; ++c) {
                if (c == idx) continue;

                if (node -> children[c] && dfs(i + 1, word, node -> children[c], cnt + 1)) return true;
            }
        }

        return false;
    }

public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (const auto& word : dictionary) {
            insert(word);
        }

        for (const auto& q : queries) {
            TrieNode* node = root;
            if (dfs(0, q, node, 0)) ans.push_back(q);
        }

        return ans;
    }
};