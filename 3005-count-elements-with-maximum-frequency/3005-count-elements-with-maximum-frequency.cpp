class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freqs;
        
        int ans = 0, maxFreq = 0, freq;
        for (int num:nums){
            ++freqs[num];
            freq = freqs[num];
            
            // If we discover a higher frequency element
            // Update mx_freq
            // Reset ans to the new maxFreq
            if (freq > maxFreq){
                maxFreq = freq;
                ans = freq;
            }
            // If we find an element with the max frequency, add it to the total
            else if (freq == maxFreq)
                ans += freq;
        }
        
        return ans;
    }
};