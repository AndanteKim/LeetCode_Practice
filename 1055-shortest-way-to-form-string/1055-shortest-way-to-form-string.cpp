class Solution {
public:
    int shortestWay(string source, string target) {
        vector<int> char_to_indices[26];
        for (int i = 0; i < source.size(); ++i){
            char_to_indices[source[i] - 'a'].push_back(i);
        }
        
        int source_iterator = 0, count = 1;
        for (int i = 0; i < target.size(); ++i){
            if (char_to_indices[target[i] - 'a'].size() == 0) return -1;
            
            vector<int> indices = char_to_indices[target[i] - 'a'];
            int index = lower_bound(indices.begin(), indices.end(), source_iterator) - indices.begin();
            
            if (index == indices.size()){
                ++count;
                source_iterator = indices[0] + 1;
            } 
            else{
                source_iterator = indices[index] + 1;
            }
        }
        
        return count;
    }
};