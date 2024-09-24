class Trie{
private:
    struct TrieNode{
        // Each node has up to 10 possible children (digits 0 ~ 9)
        TrieNode* children[10];
        
        TrieNode(){
            for (int i = 0; i < 10; ++i)
                children[i] = nullptr;
        }
    };
    
    void deleteNode(int d, TrieNode* curr){
        if (curr == nullptr)
            return;
        for (int i = 0; i < 10; ++i)
            deleteNode(i, curr -> children[i]);
    }
    
    TrieNode *root;
    
public:
    Trie(){
        root = new TrieNode();
    }
    
    // Insert a number into the Trie by treating by as a string of digits
    void insert(int num){
        TrieNode *curr = root;
        for (char& d : to_string(num)){
            int index = d - '0';
            if (!curr -> children[index])
                curr -> children[index] = new TrieNode();
            curr = curr -> children[index];
        }
    }
    
    // Find the longest common prefix for a number in arr2 with the Trie
    int findLongestPrefix(int num){
        TrieNode *curr = root;
        int length = 0;
        
        // Increase length if the current digit matches
        for (char& d : to_string(num)){
            int index = d - '0';
            
            // Stop if no match for the current digit
            if (!curr -> children[index])
                break;
            curr = curr -> children[index];
            ++length;
        }
        
        return length;
    }
    
    // Destructor
    ~Trie(){
        TrieNode* curr = root;
        for (int i = 0; i < 10; ++i)
            deleteNode(i, curr -> children[i]);
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *trie1 = new Trie(), *trie2 = new Trie();
        
        // Step 1: Insert all numbers from arr1 into the Trie
        for (int n1 : arr1)
            trie1 -> insert(n1);
        
        // Step 2: Find the longest prefix match for each number in arr2
        for (int n2 : arr2)
            trie2 -> insert(n2);
        
        // Step 2:
        int longestPrefix = 0;
        
        for (int n2 : arr2)
            longestPrefix = max(longestPrefix, trie1 -> findLongestPrefix(n2));
        
        for (int n1 : arr1)
            longestPrefix = max(longestPrefix, trie2 -> findLongestPrefix(n1));
        
        trie1 -> ~Trie();
        trie2 -> ~Trie();
        return longestPrefix;
    }
};