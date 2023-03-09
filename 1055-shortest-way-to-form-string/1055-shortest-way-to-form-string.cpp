class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> char_to_indices;
        for (int i = 0; i < source.size(); ++i){
            char_to_indices[source[i]].push_back(i);
        }
        
        int source_iterator = 0, count = 1;
        for (char& c : target){
            if (char_to_indices.find(c) == char_to_indices.end()) return -1;
            
            int index = lower_bound(char_to_indices[c].begin(), char_to_indices[c].end(), source_iterator) - char_to_indices[c].begin();
            
            if (index == char_to_indices[c].size()){
                ++count;
                source_iterator = char_to_indices[c][0] + 1;
            } 
            else{
                source_iterator = char_to_indices[c][index] + 1;
            }
        }
        
        return count;
    }
};