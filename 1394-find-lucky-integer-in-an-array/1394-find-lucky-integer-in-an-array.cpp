class Solution {
public:
    int findLucky(vector<int>& arr) {
        int lucky_max = -1;
        unordered_map<int, int> Counter;
        
        for (const int& n : arr) ++Counter[n];
        
        for (const auto&[key, value] : Counter) if (key == value) lucky_max = max(lucky_max, key);
        return lucky_max;
    }
};