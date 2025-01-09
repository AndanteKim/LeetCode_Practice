class Node{
private:
    friend class Trie;
    // Links to child nodes
    vector<Node*> links;
    // Number of strings having prefix till this node
    int count;
public:
    Node(): links(26, nullptr), count(0){}
};

class Trie{
private:
    friend class Node;
    Node* root;
public:
    Trie(){ root = new Node(); }

    // Add word to trie and update prefix counts
    void addWords(const string& word){
        Node* curr = root;
        for (const char& c : word){
            int idx = c - 97;
            if (curr -> links[idx] == nullptr){
                curr -> links[idx] = new Node();
            }
            curr = curr -> links[idx];
            curr -> count++;    // Increment count for this prefix
        }
    }

    // Return count of strings having pref as prefix
    int countPrefix(const string& pref){
        Node* curr = root;

        for (const char& c : pref){
            int idx = c - 97;
            if (curr -> links[idx] == nullptr)
                return 0;   // Prefix not found
            curr = curr -> links[idx];
        }

        return curr -> count;       // Return count at last node
    }
};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Trie *trie = new Trie();
        
        // Add all words to trie
        for (const string& word :words){
            trie -> addWords(word);
        }

        return trie -> countPrefix(pref);
    }
};