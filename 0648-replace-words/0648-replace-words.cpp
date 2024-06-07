class TrieNode{
public:
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : children(26, nullptr){
        isEnd = false;
    }
};

class Trie{
private:
    TrieNode *root;
    
public:
    Trie() {root = new TrieNode();}
    void insert(string& s){
        TrieNode *curr = root;
        for (char& c:s){
            if (curr -> children[c - 'a'] == nullptr)
                curr -> children[c - 'a'] = new TrieNode();
            curr = curr -> children[c - 'a'];
        }
        curr -> isEnd = true;
    }
    
    // Find the shortest root of the word in the trie
    string findShortest(string& word){
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i){
            if (curr -> children[word[i] - 'a'] == nullptr)
                // There is not a corresponding root in the trie
                return word;
            curr = curr -> children[word[i] - 'a'];
            if (curr -> isEnd)
                return word.substr(0, i + 1);
        }
        
        // There is not a corresponding root in the trie
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *dictTrie = new Trie();
        for (string& s:dictionary)
            dictTrie -> insert(s);
        
        // Replace eaach word in sentence with the corresponding shortest root
        string word, newSentence = "";
        istringstream isStream(sentence);
        
        while (getline(isStream, word, ' ')){
            newSentence += dictTrie -> findShortest(word) + " ";
        }
        
        newSentence.pop_back(); // remove extra space
        
        return newSentence;
    }
};