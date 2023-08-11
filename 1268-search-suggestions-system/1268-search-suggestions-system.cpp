struct TrieNode{
    vector<string> words;
    unordered_map<char, TrieNode*> children;
    TrieNode() : words({}), children(unordered_map<char, TrieNode*>()){}
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // build a trie
        TrieNode* root = new TrieNode();
        for (string& product : products){
            TrieNode* curr = root;
            for (char& c : product){
                if (curr -> children.find(c) == curr -> children.end()){
                    curr -> children[c] = new TrieNode();
                }
                curr = curr -> children[c];
                curr -> words.push_back(product);
                sort(curr -> words.begin(), curr -> words.end());
                if (curr -> words.size() > 3) curr -> words.pop_back();
            }
        }
        
        // search words
        vector<vector<string>> ans;
        TrieNode* curr = root;
        for (char& c : searchWord){
            if (curr -> children.find(c) != curr -> children.end()){
                curr = curr -> children[c];
                ans.push_back(curr -> words);
            }
            else{
                curr -> children.clear();
                ans.push_back({});
            }
        }
        return ans;
    }
};