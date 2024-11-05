class Solution {
private:
    struct TrieNode{
        bool isEndOfFolder;
        unordered_map<string, TrieNode*> children;
        TrieNode() : isEndOfFolder(false) {}
    };
    
    TrieNode* root;
    
    // Recurisvely delete all TrieNodes to prevent memory leaks
    void deleteTrie(TrieNode* node){
        if (node == nullptr) return;
        for (auto& [_, descendant] : node -> children){
            deleteTrie(descendant);
        }
        delete node;
    }
    
public:
    // Constructor initializes the root of the Trie
    Solution() : root(new TrieNode()) {}
    
    // Clean up memory
    // A destructor to recursively delete all TrieNodes and prevent memory leaks
    ~Solution() {deleteTrie(root);}
    
    vector<string> removeSubfolders(vector<string>& folder) {
        // Build Trie from folder paths
        for (string& path : folder){
            TrieNode* currNode = root;
            stringstream iss(path);
            string name;
            while (getline(iss, name, '/')){
                // Skip empty folder names
                if (name.empty()) continue;
                // Create new node if it doesn't exist
                if (!currNode -> children.count(name))
                    currNode -> children[name] = new TrieNode();
                // Mark the end of the folder path
                currNode = currNode -> children[name];
            }
            
            currNode -> isEndOfFolder = true;
        }
        
        vector<string> ans;
        for (string& path: folder){
            bool isSubstring = false;
            TrieNode* currNode = root;
            vector<string> names;
            stringstream iss(path);
            string name;
            while (getline(iss, name, '/')){
                // Skip empty foldernames
                if (name.empty()) continue;
                TrieNode* nextNode = currNode -> children[name];
                // Check if the current folder path is a subfolder of an existing folder 
                if (nextNode -> isEndOfFolder && iss.rdbuf() -> in_avail() != 0){
                    isSubstring = true;
                    break;  // Found a sub-folder
                }
                currNode = nextNode;
            }
            
            // If not a sub-folder, add to the result
            if (!isSubstring)
                ans.push_back(path);
        }
        
        return ans;
    }
};