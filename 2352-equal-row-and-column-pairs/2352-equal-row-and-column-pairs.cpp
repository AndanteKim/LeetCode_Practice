class Trie{
private:
    struct TrieNode{
        int count = 0;
        unordered_map<int, TrieNode*> children;
    };
    TrieNode *trie = new TrieNode();
public:
    Trie(){}
    
    void insert(vector<int>& arr){
        TrieNode *myTrie = trie;        
        
        for (int num : arr){
            if (myTrie -> children.find(num) == myTrie -> children.end()){
                myTrie -> children[num] = new TrieNode();
            }
            myTrie = myTrie -> children[num];
        }
        ++myTrie -> count;
    }
    
    int search(vector<int>& arr){
        TrieNode *myTrie = trie;
        
        for (int num : arr){
            if (myTrie -> children.find(num) != myTrie -> children.end()) myTrie = myTrie -> children[num];
            else return 0;
        }
        return myTrie -> count;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        Trie* myTrie = new Trie();
        int count = 0, n = grid.size();
        
        for (vector<int>& row : grid) myTrie -> insert(row);
        
        for (int col = 0; col < n;++col){
            vector<int> cols(n, 0);
            for (int row = 0; row < n; ++row) cols[row] = grid[row][col];
            count += myTrie -> search(cols);
        }
        
        return count;
    }
};