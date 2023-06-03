typedef long long ll;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll left = 1, right = *max_element(piles.begin(), piles.end());
        
        while (left <= right){
            ll mid = left + (right - left) / 2, time = 0;
            for (double pile : piles) time += ceil(pile / mid);
            if (time <= h) right = mid - 1;
            else left = mid + 1;
        }
        
        return left;
    }
};