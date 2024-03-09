class Solution {
private:
    bool isCommonPrefix(vector<string>& strs, int len){
        string s1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); ++i){
            if (strs[i].find(s1) != 0)
                return false;
        }
        
        return true;
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        int minLen = INT_MAX;
        for (string& s:strs)
            minLen = min(minLen, (int)s.size());
        
        int low = 0, high = minLen;
        
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            
            if (isCommonPrefix(strs, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return strs[0].substr(0, low + ((high - low) >> 1));
    }
};