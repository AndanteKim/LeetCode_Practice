class Solution {
    bool is_subsequence(string to_target, string in_string){
        int i = 0, j = 0;
        
        while (i < to_target.size() && j < in_string.size()){
            if (to_target[i] == in_string[j]) ++i;
            ++j;
        }
        return i == to_target.size();
    }
    
public:
    int shortestWay(string source, string target) {
        
        vector<bool> source_set(26, false);
        
        for (const char& c : source) source_set[c - 'a'] = true;
        
        for (const char& c : target){
            if (source_set[c - 'a'] == false) return -1;
        }
        string concatenated_source = source;
        int cnt = 1;
        
        while (!is_subsequence(target, concatenated_source)){
            concatenated_source += source;
            ++cnt;
        }
        
        return cnt;
    }
};