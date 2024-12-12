class Solution {
private:
    int cutRibbons(vector<int>& ribbons, int target){
        int nums = 0;
        for (int ribbon : ribbons){
            nums += ribbon / target;
        }
        return nums;
    }
    
public:
    int maxLength(vector<int>& ribbons, int k) {
        int ans = 0, left = 1, right = *max_element(ribbons.begin(), ribbons.end()), mid;
        
        while (left <= right){
            mid = left + ((right - left) >> 1);
            
            int ribs = cutRibbons(ribbons, mid);
            
            if (ribs >= k){
                ans = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        
        return ans;
    }
};