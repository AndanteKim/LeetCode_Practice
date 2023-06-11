class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> m;
        for (vector<int>& flower : flowers){
            ++m[flower[0]];
            --m[flower[1] + 1];
        }
        
        int sum = 0;
        for (auto& [key, value] : m){
            sum += value;
            value = sum;
        }
        
        int n = people.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; ++i){
            auto it = m.upper_bound(people[i]);
            if (it != m.begin()){
                --it;
                ans[i] = it -> second;
            }
        }
        
        return ans;
    }
};