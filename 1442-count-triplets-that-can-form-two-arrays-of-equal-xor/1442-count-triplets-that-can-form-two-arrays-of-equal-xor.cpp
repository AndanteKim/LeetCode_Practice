class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0, n = arr.size();
        
        // Iterate over every possible starting index i
        for (int start = 0; start <= n - 2; ++start){
            // Initialize XOR value for the subarray from start to mid - 1
            int xorA = 0;
            
            //Iterate over every possible middle index j
            for (int mid = start + 1; mid <= n - 1; ++mid){
                // Update xorA to include arr[mid - 1]
                xorA ^= arr[mid - 1];
                
                // Initialize XOR value for the subarray from mid to end
                int xorB = 0;
                
                // Iterate over each possible ending index k (starting from mid)
                for (int end = mid; end <= n - 1; ++end){
                    // Update xorB to include arr[end]
                    xorB ^= arr[end];
                    
                    // Found a valid triplet (start, mid, end)
                    if (xorA == xorB)
                        ++count;
                }
            }
        }
        
        return count;
    }
};