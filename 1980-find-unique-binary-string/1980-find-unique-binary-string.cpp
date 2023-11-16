class Solution {
private:
    string ans = "";
    int n;
    void backtrack(string& curr, vector<string>& nums){
        if (curr.size() == n){
            if (ans == "" && find(nums.begin(), nums.end(), curr) == nums.end())
                ans = curr;
            return;
        }
        
        curr.push_back('0');
        backtrack(curr, nums);
        curr.pop_back();
        
        curr.push_back('1');
        backtrack(curr, nums);
        curr.pop_back();
    }
    
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        string curr = "";
        backtrack(curr, nums);
        return ans;
    }
};