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
        unordered_map<int, int> cache;
        int n = mountainArr.length(), low = 1, high = n - 2, curr, next;
        
        while (low != high){
            int mid = low + ((high - low) >> 1);
            if (cache.find(mid) != cache.end())
                curr = cache[mid];
            else{
                curr = mountainArr.get(mid);
                cache[mid] = curr;
            }
            
            if (cache.find(mid + 1) != cache.end())
                next = cache[mid + 1];
            else{
                next = mountainArr.get(mid + 1);
                cache[mid + 1] = next;
            }
            
            if (curr < next)
                low = mid + 1;
            else
                high = mid;
        }
        
        int peakIndex = low;
        low = 0, high = peakIndex;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (cache.find(mid) != cache.end())
                curr = cache[mid];
            else
                curr = mountainArr.get(mid);
            
            if (curr == target)
                return mid;
            if (curr < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        low = peakIndex + 1, high = n - 1;
        while (low <= high){
            int mid = low + ((high - low) >> 1);
            if (cache.find(mid) != cache.end())
                curr = cache[mid];
            else
                curr = mountainArr.get(mid);
            
            if (curr == target)
                return mid;
            if (curr > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        return -1;
    }
};