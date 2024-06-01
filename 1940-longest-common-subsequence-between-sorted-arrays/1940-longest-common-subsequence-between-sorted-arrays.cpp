class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int rows = arrays.size();
        vector<int> intersect(101), ans;
        
        for (vector<int>& arr : arrays){
            for (int num : arr)
                ++intersect[num];
        }
        
        for (int i = 1; i <= 100; ++i)
            if (intersect[i] == rows)
                ans.push_back(i);
        
        return ans;
    }
};