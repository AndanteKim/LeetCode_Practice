class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencies;
        for (int num : nums) ++frequencies[num];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        
        for (auto& [key, val] : frequencies) {
            if (heap.size() < k) heap.push({val, key});
            else if (heap.size() >= k && heap.top().first < val){
                heap.pop();
                heap.push({val, key});
            }
        }
        vector<int> ans;
        while(!heap.empty()) {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        
        return ans;
    }
};