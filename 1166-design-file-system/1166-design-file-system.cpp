class FileSystem {
private:
    unordered_map<string, int> paths;

public:
    FileSystem() {}
    
    bool createPath(string path, int value) {
        // Step-1: Basic path validations
        if (path == "/" || path.size() == 0 || paths.contains(path)) return false;

        // Step-2: If the parent doesn't exist. Note that "/" is a valid parent.
        string parent = path.substr(0, path.rfind('/'));
        if (parent.size() > 1 && !paths.contains(parent)) return false;

        // Step-3: add this new path and return true.
        paths[path] = value;
        return true;
    }
    
    int get(string path) {
        return !paths.contains(path)? -1 : paths[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */