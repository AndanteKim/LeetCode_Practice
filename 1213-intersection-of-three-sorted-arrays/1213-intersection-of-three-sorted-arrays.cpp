class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        map<int, int> counter;
        
        // Concatenate all vectors together
        for (int num : arr1) ++counter[num];
        for (int num : arr2) ++counter[num];
        for (int num : arr3) ++counter[num];
        
        for (auto& [num, freq] : counter){
            if (freq == 3) ans.push_back(num);
        }
        return ans;
    }
};