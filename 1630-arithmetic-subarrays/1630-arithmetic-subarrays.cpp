class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        vector<vector<int>> queries;
        
        for (int i = 0; i < l.size(); ++i){
            vector<int> query(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(query.begin(), query.end());
            queries.push_back(query);
        }
        
        for (vector<int>& query : queries){
            int arithmetic = query[1] - query[0];
            bool flag = true;
            
            for (int i = 1; i < query.size(); ++i){
                if (query[i - 1] + arithmetic != query[i]){
                    flag = false;
                    break;
                }
            }
            
            ans.push_back(flag);
        }
        
        return ans;
    }
};