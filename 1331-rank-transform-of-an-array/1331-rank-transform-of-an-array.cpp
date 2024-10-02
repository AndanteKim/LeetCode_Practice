class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> rank = arr;
        unordered_map<int, int> mapping;
        int i = 1;
        sort(rank.begin(), rank.end());
        
        for (int num : rank){
            if (mapping.count(num))
                continue;
            mapping[num] = i++;
        }
        
        vector<int> ans(arr.size());
        i = 0;
        for (int num : arr)
            ans[i++] = mapping[num];
        
        return ans;
    }
};