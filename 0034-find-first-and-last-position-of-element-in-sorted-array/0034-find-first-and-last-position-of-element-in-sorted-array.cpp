class Solution {
private:
    int findBound(vector<int>& nums, int target, bool isFirst){
        int begin = 0, end = nums.size() - 1;
        
        while (begin <= end){
            int mid = begin + ((end - begin) >> 1);
            if (nums[mid] == target){
                // find lower bound
                if (isFirst){
                    if (mid == begin || nums[mid - 1] < target)
                        return mid;
                    else
                        --end;
                }
                else{
                    if (mid == end || nums[mid + 1] > target)
                        return mid;
                    else
                        ++begin;
                }
            }
            else if (nums[mid] > target)
                --end;
            else
                ++begin;
        }
        
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findBound(nums, target, true);
        if (left == -1)
            return vector<int>{-1, -1};
        int right = findBound(nums, target, false);
        return vector<int>{left, right};
    }
};