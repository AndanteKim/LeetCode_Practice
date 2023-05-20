class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> frequencies;
        
        for (int num : arr) ++frequencies[num];
        vector<int> ordered;
        for (auto& [key, val] : frequencies) ordered.push_back(val);
        sort(ordered.begin(), ordered.end(), [](int a, int b){return a > b;});
        
        while (k > 0){
            int val = ordered.back();
            if (val <= k){
                k -= val;
                ordered.pop_back();
            }
            else break;
        }
        
        return ordered.size();
    }
};