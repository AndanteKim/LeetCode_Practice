struct TrieNode{
    int count;
    unordered_map<int, TrieNode*> children;
    TrieNode() : count(0), children(){
    }
};

class Trie{
public:
    TrieNode* trie = new TrieNode();
    Trie(){}
    
    void insert(vector<int>& array){
        TrieNode* myTrie = trie;
        for (int num : array){
            if (myTrie -> children.find(num) == myTrie -> children.end()){
                myTrie -> children[num] = new TrieNode();
            }
            myTrie = myTrie -> children[num];
        }
        ++myTrie -> count;
    }
    
    int search(vector<int>& array){
        TrieNode* myTrie = trie;
        for (int num : array){
            if (myTrie -> children.find(num) != myTrie -> children.end())
                myTrie = myTrie -> children[num];
            else return 0;
        }
        
        return myTrie -> count;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        Trie *myTrie = new Trie();
        int count = 0, n = grid.size();
        
        for (vector<int>& row : grid) myTrie -> insert(row);
        
        for (int c = 0; c < n; ++c){
            vector<int> colArr(n);
            for (int r = 0; r < n; ++r)
                colArr[r] = grid[r][c];
            count += myTrie -> search(colArr);
        }
        
        return count;
    }
};