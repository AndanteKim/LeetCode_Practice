class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size(), count = 0, prefix = 0;
        
        // Maps to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap, totalMap;
        countMap[0] = 1;
        
        // Iterating through the array
        for (int i = 0; i < n; ++i){
            // Calculating XOR prefix
            prefix ^= arr[i];
            
            // Calculating contribution of current element to the result
            count += countMap[prefix] * i - totalMap[prefix]; 
            
            // Updating total count of current XOR value
            totalMap[prefix] += i + 1;
            ++countMap[prefix];
        }
        
        return count;
    }
};