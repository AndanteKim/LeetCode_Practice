class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for (int i = 0; i < nums.size(); ++i){
            char digit = nums[i][i];
            ans.push_back(digit == '1'? '0':'1');
        }
        return ans;
    }
};