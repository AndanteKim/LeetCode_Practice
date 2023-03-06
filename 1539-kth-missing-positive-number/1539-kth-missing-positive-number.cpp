class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (k <= arr[0] - 1) return k;
        k -= arr[0] - 1;
        
        for (int i = 0; i < arr.size() - 1; ++i){
            int curr_missing = arr[i+1] - arr[i] - 1;
            
            if (k <= curr_missing) return arr[i] + k;
            
            k -= curr_missing;
        }
        return arr.back() + k;
    }
};