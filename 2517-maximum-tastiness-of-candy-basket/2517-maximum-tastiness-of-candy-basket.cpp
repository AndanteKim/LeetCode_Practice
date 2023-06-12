class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int left = 0, right = price.back() - price[0], n = price.size();
        
        while (left < right){
            int mid = left + ((right - left + 1) >> 1), cnt = 1;
            for (int i = 1, j = 0; i < n; ++i){
                if (price[i] - price[j] >= mid){
                    ++cnt;
                    j = i;
                }
            }
            
            if (cnt >= k) left = mid;
            else right = mid - 1;
        }
        
        return left;
    }
};