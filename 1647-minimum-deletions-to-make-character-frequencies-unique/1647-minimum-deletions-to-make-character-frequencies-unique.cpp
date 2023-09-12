class Solution {
public:
    int minDeletions(string s) {
        
        // store the frequency orf each character
        vector<int> frequencies(26);
        for (char& c : s){
            ++frequencies[c - 'a'];
        }
        
        // Use a set to store the frequencies we've already seen
        unordered_set<int> seen;
        int ans = 0;
        for (int i = 0; i < 26; ++i){
            // keep decrementing the frequency until it is unique
            while (frequencies[i] && seen.find(frequencies[i]) != seen.end()){
                --frequencies[i];
                ++ans;
            }
            // add the newly occupied frequency to the set
            seen.insert(frequencies[i]);
        }
        
        return ans;
    }
};