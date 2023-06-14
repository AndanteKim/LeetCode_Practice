typedef long long ll;

class Solution {
private:
    bool feasible(int days, vector<int>& bloomDay, int m, int k){
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay){
            if (bloom > days) flowers = 0;
            else{
                bouquets += (flowers + 1) / k;
                flowers = (flowers + 1) % k;
            }
        }
        
        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (ll)m * k) return -1;
        
        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (feasible(mid, bloomDay, m, k)) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};