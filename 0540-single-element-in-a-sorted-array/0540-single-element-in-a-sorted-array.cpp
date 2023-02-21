class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, mid;
        bool halves_are_even;
        while (low < high){
            mid = low + (high - low) / 2;
            halves_are_even = (high - mid) % 2 == 0;
            
            if (nums[mid] == nums[mid + 1]){
                if (halves_are_even) low = mid + 2;
                else high = mid - 1;
            }
            else if (nums[mid - 1] == nums[mid]){
                if (halves_are_even) high = mid - 2;
                else low = mid + 1;
            }
            else return nums[mid];
        }
        return nums[low];
    }
};