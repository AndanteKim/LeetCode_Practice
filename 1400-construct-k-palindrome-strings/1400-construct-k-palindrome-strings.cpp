class Solution {
public:
    bool canConstruct(string s, int k) {
        // Base case 1
        if (s.size() < k)
            return false;
        
        // Base case 2
        if (s.size() == k)
            return true;

        // Initialize frequency array and oddCount integer
        vector<int> freq(26, 0);
        int oddCount = 0;
        
        // Increment the value of index corresponding to the current character
        for (const char& c : s){
            ++freq[c - 'a'];
        }

        // Count the number of characters appearing an odd number of times in s
        for (int i = 0; i < 26; ++i)
            if (freq[i] % 2)
                ++oddCount;

        // Return true if the number of odd frequencies is less than or equal to k
        return oddCount <= k;
    }
};