class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int volume, int k) {
        int n = heights.size();
        vector<int> ans = heights;

        for (int v = 0; v < volume; ++v) {
            bool ND = true;
            for (int d : vector<int>{-1, 1}) {
                int i, best;
                i = best = k;
                for (;(0 <= (i + d)) && ((i + d) < n) && (ans[i + d] <= ans[i]); i += d) {
                    if (ans[i + d] < ans[i]) best = i + d;
                }

                if (best != k) {
                    ++ans[best];
                    ND = false;
                    break;
                }
            }

            if (ND) ++ans[k]; 
        }

        return ans;
    }
};