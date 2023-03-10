class Solution {
public:
    int shortestWay(string source, string target) {
        int source_length = source.size();
        int nextOccurrence[source.length()][26];
        
        for (int c = 0; c < 26; ++c) nextOccurrence[source.size() - 1][c] = -1;
        
        nextOccurrence[source.size() - 1][source[source.size() - 1] - 'a'] = source.size() - 1;
        
        for (int idx = source.size() - 2; idx >= 0; --idx){
            for (int c = 0; c < 26; ++c) nextOccurrence[idx][c] = nextOccurrence[idx + 1][c];
            
            nextOccurrence[idx][source[idx] - 'a'] = idx;
        }
        
        int source_iterator = 0, count = 1;
        
        for (const char&c : target){
            if (nextOccurrence[0][c - 'a'] == -1) return -1;
            
            if (source_iterator == source.size() || nextOccurrence[source_iterator][c - 'a'] == -1){
                ++count;
                source_iterator = 0;
            }
            
            source_iterator = nextOccurrence[source_iterator][c - 'a'] + 1;
        }
        
        return count;
        
    }
};