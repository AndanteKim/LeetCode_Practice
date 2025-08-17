class FileSystem {
private:
    struct TrieNode{
        unordered_map<string, TrieNode*> children;
        int value;

        TrieNode(): value(-1){}
    };
    TrieNode *root;

public:
    FileSystem() {
        root = new TrieNode();
    }
    
    bool createPath(string path, int value) {
        vector<string> components;
        stringstream ss(path);
        string component = "";

        while (getline(ss, component, '/')){
            components.push_back(component);
        }

        TrieNode *curr = root;
        for (int i = 1; i < components.size(); ++i){
            if (!curr -> children.contains(components[i])){
                if (i != components.size() - 1) return false;
                curr -> children[components[i]] = new TrieNode();
            }
            curr = curr -> children[components[i]];
        }

        if (curr -> value != -1) return false;

        curr -> value = value;

        return true;
    }
    
    int get(string path) {
        vector<string> components;
        stringstream ss(path);
        string component = "";
        TrieNode* curr = root;

        while (getline(ss, component, '/')){
            components.push_back(component);
        }
        
        int ans = -1;
        for (int i = 1; i < components.size(); ++i){
            if (!curr -> children.contains(components[i])) return -1;
            curr = curr -> children[components[i]];
        }

        return curr -> value;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */