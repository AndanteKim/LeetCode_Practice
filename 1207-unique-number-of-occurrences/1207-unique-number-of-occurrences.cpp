class Solution {
public:
    // constant to make elements non-negative
    static constexpr int k = 1000;
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2* k + 1);
        
        for (int &num : arr) ++freq[num + k];
        
        sort(freq.begin(), freq.end());
        
        for (int i = 0; i < 2 * k; ++i) if (freq[i] && freq[i] == freq[i+1]) return false;
        
        return true;
    }
};