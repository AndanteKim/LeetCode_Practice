class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size(), ans = 0;
        vector<int> total(1001);

        for (int j = 0; j < n; ++j){
            for (int k = j + 1; k < n; ++k){
                if (abs(arr[j] - arr[k]) <= b){
                    int lj = arr[j] - a, rj = arr[j] + a;
                    int lk = arr[k] - c, rk = arr[k] + c;
                    int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
                    if (l <= r)
                        ans += (l == 0)? total[r] : total[r] - total[l - 1]; 
                }
            }

            for (int k = arr[j]; k <= 1000; ++k)
                ++total[k];
        }

        return ans;
    }
};