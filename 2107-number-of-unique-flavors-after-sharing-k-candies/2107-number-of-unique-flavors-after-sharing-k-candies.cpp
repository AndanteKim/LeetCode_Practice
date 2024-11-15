class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        int uniqueFlavor = 0, usedInWindow = 0;
        
        // Store the total number of unique flavors in the array.
        unordered_map<int, int> flavorFrequencies;
        for (int candy : candies){
            if (flavorFrequencies[candy] == 0)
                ++uniqueFlavor;
            ++flavorFrequencies[candy];
        }
        
        // Get the flavors used completely in the window.
        for (int i = 0; i < k; ++i){
            --flavorFrequencies[candies[i]];
            if (flavorFrequencies[candies[i]] == 0)
                ++usedInWindow;
        }
        
        // Get the flavors in the remaining array currently.
        int ans = uniqueFlavor - usedInWindow, n = candies.size();
        
        // Slide the window to the right.
        for (int i = k; i < n; ++i){
            // Remove the candy on the left end from the window.
            ++flavorFrequencies[candies[i - k]];
            if (flavorFrequencies[candies[i - k]] == 1)
                --usedInWindow;
            
            // Add the candy on the right end at index i
            --flavorFrequencies[candies[i]];
            if (flavorFrequencies[candies[i]] == 0)
                ++usedInWindow;
            
            ans = max(ans, uniqueFlavor - usedInWindow);
        }
        
        return ans;
    }
};