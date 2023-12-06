class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), start = 0, count = 0;
        k %= n;
        
        while (count < n){
            int current = start, prev = nums[start];
            while (true){
                int nextIdx = (current + k) % n;
                swap(nums[nextIdx], prev);
                current = nextIdx;
                ++count;
                if (start == current)
                    break;
            }
            ++start;
        }
    }
};