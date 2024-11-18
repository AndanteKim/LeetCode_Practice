class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i){
            int curr = 0;
            if (k > 0){
                for (int di = 1; di <= k; ++di)
                    curr += code[(i + di) % n];
            }
            else{
                for (int di = 1; di <= abs(k); ++di)
                    curr += code[(i - di + n) % n];
            }
            
            ans[i] = curr;
        }
        
        return ans;
    }
};