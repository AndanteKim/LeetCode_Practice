class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        set<pair<int, int>> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        visited.insert({0, 0});
        pq.push({nums1[0] + nums2[0], {0, 0}});
        vector<vector<int>> ans;
        
        while (!pq.empty() && k > 0){
            auto [sum, coord] = pq.top();
            int i = coord.first, j = coord.second;
            pq.pop();
            ans.push_back(vector<int>{nums1[i], nums2[j]});
            
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()){
                visited.insert({i + 1, j});
                pq.push({nums1[i + 1] + nums2[j], {i + 1, j}});
            }
            
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()){
                visited.insert({i, j + 1});
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
            --k;
        }
        return ans;
    }
};