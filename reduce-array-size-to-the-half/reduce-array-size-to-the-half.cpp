class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> frequencies;
        for (int i : arr) ++frequencies[i];
        priority_queue<int, vector<int>> freq;
        int total = 0, ans = 0, n = arr.size();
        for (auto& [key, val] : frequencies) {
            freq.push(val);
            total += val;
        }
        
        while (total > n / 2){
            total -= freq.top();
            freq.pop();
            ++ans;
        }
        
        return ans;
    }
};