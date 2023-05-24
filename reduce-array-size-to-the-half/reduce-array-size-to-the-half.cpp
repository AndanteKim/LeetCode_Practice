class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> frequencies;
        for (int i : arr) ++frequencies[i];
        vector<int> freq;
        int total = 0, ans = 0, n = arr.size();
        for (auto& [key, val] : frequencies) {
            freq.push_back(val);
            total += val;
        }
        sort(freq.begin(), freq.end());
        
        while (total > n / 2){
            total -= freq.back();
            freq.pop_back();
            ++ans;
        }
        
        return ans;
    }
};