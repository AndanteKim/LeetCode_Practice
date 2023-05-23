class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        int size = *max_element(weight.begin(), weight.end()) + 1;
        vector<int> counting(size);
        for (int w: weight) ++counting[w];
        int ans = 0, units = 0;
        
        for (int i = 0; i < size; ++i){
            if (counting[i]){
                int take = min(counting[i], (5000 - units) / i);
                if (take == 0) break;
                ans += take;
                units += take * i;
            }
        }
        
        return ans;
    }
};