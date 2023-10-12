/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low = 1, high = mountainArr.length() - 2, peakIndex;
        
        // find the peak index of the array
        while (low < high){
            int mid = low + ((high - low) >> 1);
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        peakIndex = low;
        
        // find the target in the increasing array
        low = 0, high = peakIndex;
        while (low < high){
            int mid = low + ((high - low) >> 1);
            if (mountainArr.get(mid) < target)
                low = mid + 1;
            else
                high = mid;
        }
        if (mountainArr.get(low) == target) return low;
        
        // find the target in the decreasing array
        low = peakIndex + 1, high = mountainArr.length() - 1;
        while (low < high){
            int mid = low + ((high - low) >> 1);
            if (mountainArr.get(mid) > target)
                low = mid + 1;
            else
                high = mid;
        }
        if (mountainArr.get(low) == target) return low;
        
        return -1;
    }
};