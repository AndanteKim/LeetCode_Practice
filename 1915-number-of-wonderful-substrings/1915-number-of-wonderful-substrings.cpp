class Solution {
public:
    long long wonderfulSubstrings(string word) {
        // Create the frequency map
        // key = bitmask, value = frequency of bitmask key
        unordered_map<long long, int> freq;
        
        // The empty prefix can be the smaller prefix, which is handled like this.
        freq[0] = 1;
        long long ans = 0, mask = 0;
        
        for (char& c : word){
            int bit = c - 'a';
            
            // Flip the parity of the c-th bit in the running prefix mask
            mask ^= (1 << bit);
            
            // Count smaller prefixes creating substrings with no odd occurring letters.
            if (freq.find(mask) != freq.end()){
                ans += freq[mask];
                ++freq[mask];
            }
            else
                freq[mask] = 1;
        
        
            // Loop through every possible letter that can appear an odd number of times in a substring.
            for (int oddC = 0; oddC < 10; ++oddC){
                if (freq.find(mask ^ (1 << oddC)) != freq.end())
                    ans += freq[mask ^ (1 << oddC)];
            }
        }
        
        return ans;
    }
};