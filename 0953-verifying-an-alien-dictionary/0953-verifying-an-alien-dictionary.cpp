class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> lookup;
        for (int i = 0; i < order.size(); ++i) lookup[order[i]] = i;
        
        for (int i = 0; i < words.size()-1; ++i){
            for (int j = 0; j < words[i].size(); ++j){
                if (j >= words[i+1].size()) return false;
                
                if (words[i][j] != words[i+1][j]){
                    if (lookup[words[i][j]] > lookup[words[i+1][j]]) return false;    
                    break;
                }
            }
        }
        
        return true;
    }
};