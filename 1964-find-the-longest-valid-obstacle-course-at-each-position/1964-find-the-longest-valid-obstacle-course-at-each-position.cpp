class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 1), increasing;
        for (int i = 0; i < n; ++i){
            int idx = upper_bound(increasing.begin(), increasing.end(), obstacles[i]) - increasing.begin();
            if (idx == increasing.size()) increasing.push_back(obstacles[i]);
            else increasing[idx] = obstacles[i];
            ans[i] = idx + 1;
        }
        
        return ans;
    }
};