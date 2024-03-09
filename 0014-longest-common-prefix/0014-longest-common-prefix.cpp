class Solution {
private:
    string commonPrefix(string& left, string& right){
        int mn = min(left.size(), right.size());
        
        for (int i = 0; i < mn; ++i){
            if (left[i] != right[i])
                return left.substr(0, i);
        }
        
        return left.substr(0, mn);
    }
    
    string longestCommonPrefix(vector<string>& strs, int left, int right){
        if (left == right) return strs[left];
        else {
            int mid = left + ((right - left) >> 1);
            string lcpLeft = longestCommonPrefix(strs, left, mid);
            string lcpRight = longestCommonPrefix(strs, mid + 1, right);
            return commonPrefix(lcpLeft, lcpRight);
        }
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].size() == 0) return "";
        
        return longestCommonPrefix(strs, 0, strs.size() - 1);
    }
};