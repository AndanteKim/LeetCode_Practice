class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Create a set to store all folder paths for fast lookup
        unordered_set<string> folderSet(folder.begin(), folder.end());
        vector<string> ans;
        
        // Iterate through each folder to check if it's a sub-folder
        for (const string& f : folder){
            string prefix = f;
            bool isSubFolder = false;
            
            // Check all prefixes of the current folder path
            while (!prefix.empty()){
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos) break;
                
                // Reduce the prefix to its parent folder
                prefix = prefix.substr(0, pos);
                
                // If the parent folder exists in the set, mark as sub-folder
                if (folderSet.count(prefix)){
                    isSubFolder = true;
                    break;
                }
            }
            
            // If not a sub-folder, add it to the result
            if (!isSubFolder)
                ans.push_back(f);
        }
        
        return ans;
    }
};