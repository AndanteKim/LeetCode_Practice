class Solution {
public:
    int getLucky(string s, int k) {
        string convertS = "";
        
        for (const auto& c : s)
            convertS.append(to_string(int(c) - 96));
        
        int transform = 0;
        
        for (int _ = 0; _ < k; ++_){
            transform = 0;
            for (const auto& c : convertS){
                transform += c - 48;
            }
            
            convertS = to_string(transform);
        }
        
        return transform;
    }
};