class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> dq(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i){
            int elem = dq.back();
            dq.pop_back();
            dq.push_front(elem);
        }
        
        for (int i = 0; i < nums.size(); ++i){
            nums[i] = dq.front();
            dq.pop_front();
        }
    }
};