class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> prefixXor(arr.begin(), arr.end());
        prefixXor.insert(prefixXor.begin(), 0);
        int n = prefixXor.size(), count = 0;
        
        // Performing XOR operation on the array elements
        for (int i = 1; i < n; ++i)
            prefixXor[i] ^= prefixXor[i - 1];
        
        // Dictionaries to store counts and totals of XOR values encountered
        unordered_map<int, int> countMap, totalMap;
        
        // Iterating through the array
        for (int i = 0; i < n; ++i){
            // Calculating contribution of current element to the result
            count += (countMap[prefixXor[i]] * (i - 1) - totalMap[prefixXor[i]]);
            
            // Updating total count of current XOR value
            totalMap[prefixXor[i]] += i;
            ++countMap[prefixXor[i]];
        }
        return count;
    }
};