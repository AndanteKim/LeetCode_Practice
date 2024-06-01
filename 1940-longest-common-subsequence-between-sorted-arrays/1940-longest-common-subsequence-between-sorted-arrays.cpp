class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int rows = arrays.size();
        vector<int> intersect(101), ans;
        
        for (vector<int>& arr : arrays){
            for (int num : arr){
                ++intersect[num];
                if (intersect[num] == rows)
                    ans.push_back(num);
            }
        }
        
        return ans;
    }
};