class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        unordered_map<int, int> hash_table;
        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;
        
        int i = 0;
        while (i < k) lo.push(nums[i++]);
        for (int j = 0; j < k / 2; ++j){
            hi.push(lo.top());
            lo.pop();
        }
        
        while (true){
            ans.push_back(k & 1? lo.top() : ((double)lo.top() + (double)hi.top()) * 0.5);
            if (i >= nums.size()) break;
            
            int outNum = nums[i - k], inNum = nums[i++], balance = 0;
            
            balance += (outNum <= lo.top()? -1 : 1);
            ++hash_table[outNum];
            
            if (!lo.empty() && inNum <= lo.top()){
                ++balance;
                lo.push(inNum);
            }
            else{
                --balance;
                hi.push(inNum);
            }
            
            if (balance < 0) {
                lo.push(hi.top());
                hi.pop();
                ++balance;
            }
            
            if (balance > 0){
                hi.push(lo.top());
                lo.pop();
                --balance;
            }
            
            while (hash_table[lo.top()]){
                --hash_table[lo.top()];
                lo.pop();
            }
            
            while (!hi.empty() && hash_table[hi.top()]){
                --hash_table[hi.top()];
                hi.pop();
            }
        }
        return ans;
    }
};