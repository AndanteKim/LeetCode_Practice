class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = std::numeric_limits<int>::min(), n = energy.size(), total;

        for (int i = n - k; i < n; ++i){
            total = 0;
            for (int j = i; j >= 0; j -= k){
                total += energy[j];
                ans = max(ans, total);
            }
        }

        return ans;
    }
};