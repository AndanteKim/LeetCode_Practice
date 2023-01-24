class NumArray {
    vector<int> prefix_sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix_sum.resize(n+1, 0);
        
        for (int i = 1; i <= n; ++i){
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix_sum[right+1] - prefix_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */