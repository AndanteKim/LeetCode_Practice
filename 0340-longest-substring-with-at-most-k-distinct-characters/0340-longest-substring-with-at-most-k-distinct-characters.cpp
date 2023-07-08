class Solution {
private:
    int n, k;
    bool isValid(int size, string& s){
        unordered_map<char, int> count;
        for (int i = 0; i < size; ++i) ++count[s[i]];
        if (count.size() <= k) return true;
        for (int i = size; i < n; ++i){
            ++count[s[i]];
            --count[s[i - size]];
            if (count[s[i - size]] == 0) count.erase(s[i - size]);
            if (count.size() <= k) return true;
        }
        return false;
    }
    
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        n = s.size();
        this -> k = k;
        if (k >= n) return n;
        
        int left = k, right = n;
        while (left < right){
            int mid = left + ((right - left + 1) >> 1);
            if (isValid(mid, s)) left = mid;
            else right = mid - 1;
        }
        
        return left;
    }
};