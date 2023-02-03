class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> frequency;
        vector<int> values_list;
        for (const int& num : arr) ++frequency[num];
        for (const auto&[key, value] : frequency) values_list.push_back(value);
        set<int> unique_val(values_list.begin(), values_list.end());
        return values_list.size() == unique_val.size()? true : false;
    }
};