class NumArray {
private:
    vector<int> prefix_sum{0};
    int partial_total = 0;
public:
    NumArray(vector<int>& nums) {
        for (const auto &num : nums){
            partial_total += num;
            prefix_sum.push_back(partial_total);
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