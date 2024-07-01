class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int combo = 0;
        for (int num : arr){
            if (num % 2)
                ++combo;
            else combo = 0;
            
            if (combo == 3) return true;
        }
        
        return false;
    }
};