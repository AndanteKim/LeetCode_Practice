class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end()), mid, hours_spent;
        
        while (left < right){
            mid = left + (right - left) / 2;
            hours_spent = 0;
            
            for (int pile : piles) hours_spent += (double)pile / mid != pile / mid? pile / mid + 1: pile / mid;
            
            if (hours_spent <= h) right = mid;
            else left = mid + 1;
        }
        
        return left;
    }
};