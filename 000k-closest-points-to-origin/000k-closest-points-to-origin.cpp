#define ll long long

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        
        for (vector<int>& point: points){
            int euclidian_dist = point[0] * point[0] + point[1] * point[1];
            pq.push(make_pair(-euclidian_dist, point));
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};