class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        
        for (int num : arr){
            int diff = abs(num - x);
            
            pq.push(make_pair(diff, num));
            if (pq.size() > k) pq.pop();
        }
        
        vector<int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};