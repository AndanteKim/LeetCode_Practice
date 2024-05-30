class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size() + 1, count = 0;
        vector<int> prefixXor(n);
        
        // Iterate through consecutive element in the modified array
        for (int i = 1; i < n; ++i)
            prefixXor[i] = prefixXor[i - 1] ^ arr[i - 1]; 
        
        // Iterate through the modified array to count triplets
        for (int start = 0; start < n; ++start){
            for (int end = start + 1; end < n; ++end){
                if (prefixXor[start] == prefixXor[end]){
                    // Increment the result by the count of valid triplets
                    count += end - start - 1;
                }
            }
        }
        
        return count;
    }
};