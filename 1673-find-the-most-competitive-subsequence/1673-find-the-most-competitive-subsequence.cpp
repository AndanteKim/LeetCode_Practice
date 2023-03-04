class Solution {
    deque<int>* queue;
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        queue = new deque<int>;
        vector<int> ans;
        int additionalCount = nums.size() - k;
        
        for (int i = 0; i < nums.size(); ++i){
            while (!queue -> empty() && queue -> back() > nums[i] && additionalCount > 0){
                queue -> pop_back();
                --additionalCount;
            }
            queue -> push_back(nums[i]);
        }
        
        for (int i = 0; i < k; ++i) {
            ans.push_back(queue -> front());
            queue -> pop_front();
        }
        
        return ans;
    }
};