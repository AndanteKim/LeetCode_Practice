class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int remain = ((int)arr.size()) >> 1;
        
        for (int num : arr){
            int target = ((-num % k) + k) % k;
            
            if (freq[target] > 0){
                --freq[target];
                --remain;
            }
            else{
                ++freq[((num % k) + k) % k];
            }
        }
        
        return remain == 0;
    }
};