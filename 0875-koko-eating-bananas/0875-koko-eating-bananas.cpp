class Solution {
private:
    bool isPossible(vector<int>& piles, int k, int h){
        int time = 0;
        for (int pile : piles){
            time += ceil((double)pile / k);
        }
        return time <= h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1'000'000'000;
        
        while (left < right){
            int mid = (left + ((right - left) >> 1));
            if (isPossible(piles, mid, h))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};