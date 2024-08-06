class Solution {
public:
    int minimumPushes(string word) {
        // Frequency vector to store the number for each characters
        vector<int> freq(26);
        
        for (char &c : word)
            ++freq[c - 'a'];
        
        // Sort the frequency in descending order
        sort(freq.begin(), freq.end(), [](int a, int b){return a > b;});
        
        int ans = 0;
        
        // Calculate the total number of presses
        for (int i = 0; i < 26; ++i){
            if (freq[i] == 0)
                break;
            ans += ((i / 8) + 1) * freq[i];
        }
        
        return ans;
    }
};