class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        
        for (int i = 0; i < mat.size(); ++i){
            pq.push(make_pair(count(mat[i].begin(), mat[i].end(), 1), i));
        }
        
        for (int i = 0; i < k; ++i){
            auto [weak, idx] = pq.top();
            pq.pop();
            ans.push_back(idx);
        }
        
        return ans;
    }
};