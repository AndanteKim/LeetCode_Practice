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
        int length = mountainArr.length(), low = 1, high = length - 2, curr, next;

        while (low < high){
            int mid = low + ((high - low) >> 1);
            curr = mountainArr.get(mid);
            next = mountainArr.get(mid + 1);
            
            if (curr < next){
                if (curr == target)
                    return mid;
                if (next == target)
                    return mid + 1;
                low = mid + 1;
            }
            else
                high = mid;
        }
        
        int peakIndex = low;
        low = 0, high = peakIndex;
        
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            curr = mountainArr.get(mid);
            if (curr == target)
                return mid;
            else if (curr < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        low = peakIndex + 1, high = length - 1;
        
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            curr = mountainArr.get(mid);
            if (curr == target)
                return mid;
            else if (curr > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
};