class Solution {
private:
    int binarySearch(vector<int>& row){
        int left = 0, right = row.size();
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (row[mid] == 1) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        vector<int> ans;
        
        for (int i = 0; i < mat.size(); ++i){
            int strength = binarySearch(mat[i]);
            pair<int, int> entry = make_pair(strength, i);
            pq.push(entry);
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()){
            auto [strength, idx] = pq.top();
            pq.pop();
            ans.push_back(idx);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};