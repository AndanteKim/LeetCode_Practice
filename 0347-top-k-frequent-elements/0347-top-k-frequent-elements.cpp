class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashTable;
        
        for (int num : nums) ++hashTable[num];
        
        priority_queue<pair<int, int>> heap;
        
        for (auto& [key, val] : hashTable){
            heap.push({-val, key});
            if (heap.size() > k) heap.pop();
        }
        
        vector<int> ans;
        while (!heap.empty()){
            ans.push_back(heap.top().second);
            heap.pop();
        }
        
        return ans;
    }
};