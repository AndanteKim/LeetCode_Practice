class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size();
        
        while (left < right){
            int mid = left + ((right - left) >> 1);
            if (arr[mid] < arr[mid + 1]) left = mid + 1;
            else right = mid;
        }
        
        return left;
    }
};