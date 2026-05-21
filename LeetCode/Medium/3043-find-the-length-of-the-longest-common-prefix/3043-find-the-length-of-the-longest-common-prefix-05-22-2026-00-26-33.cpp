class Solution {
private:
    struct TrieNode {
        bool isEnd= false;
        unordered_map<char, TrieNode*> children;
    };

    void insert(TrieNode* node, string num) {
        for (const char& d : num) {
            if (!node -> children.contains(d)) node -> children[d] = new TrieNode();
            node = node -> children[d];
        }
        node -> isEnd = true;
    }

    int search(TrieNode* node, string num) {
        int prefix = 0;
        for (const char& d : num) {
            if (!node -> children.contains(d)) return prefix;
            ++prefix;
            node = node -> children[d];
        }

        return prefix;
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        TrieNode* root = new TrieNode();

        for (int num : arr1) {
            TrieNode* node = root;
            insert(node, to_string(num));
        }

        for (int num : arr2) {
            TrieNode* node = root;
            ans = max(ans, search(node, to_string(num)));
        }

        return ans;
    }
};