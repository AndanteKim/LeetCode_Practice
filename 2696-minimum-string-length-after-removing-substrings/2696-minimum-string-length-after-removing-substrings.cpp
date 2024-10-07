class Solution {
public:
    int minLength(string s) {
        string minStr = "";
        
        for (const auto& c : s){
            minStr.push_back(c);
            if (minStr.size() >= 2){
                string subs = minStr.substr(minStr.size() - 2, 2);
                if (subs == "AB" || subs == "CD"){
                    minStr.pop_back();
                    minStr.pop_back();
                }
            }       
        }
        
        return minStr.size();
    }
};