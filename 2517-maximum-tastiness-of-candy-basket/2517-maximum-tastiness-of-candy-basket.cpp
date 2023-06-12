class Solution {
private:
    bool check(int x, vector<int>& price, int k, int n){
        int last = price[0], cnt = 1, i = 1;
        while (i < n && cnt < k){
            if (price[i] - last >= x){
                last = price[i];
                ++cnt;
            }
            ++i;
        }
        
        return cnt == k;
    }
        
public:
    int maximumTastiness(vector<int>& price, int k) {
        int left = 0, right = pow(10, 9), n = price.size();
        sort(price.begin(), price.end());
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (check(mid, price, k, n)) left = mid + 1;
            else right = mid;
        }
        
        return left - 1;
    }
};