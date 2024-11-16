class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> ans(length - k + 1, -1);
        deque<int> indexDeque;
        
        for (int currIndex = 0; currIndex < length; ++currIndex){
            if (!indexDeque.empty() && indexDeque.front() < currIndex - k + 1)
                indexDeque.pop_front();
            
            if (!indexDeque.empty() && nums[currIndex - 1] + 1 != nums[currIndex])
                indexDeque.clear();
            
            indexDeque.push_back(currIndex);
            
            if (currIndex >= k - 1){
                if (indexDeque.size() == k)
                    ans[currIndex - k + 1] = nums[indexDeque.back()];
                else
                    ans[currIndex - k + 1] = -1;
            }
        }
        
        return ans;
    }
};