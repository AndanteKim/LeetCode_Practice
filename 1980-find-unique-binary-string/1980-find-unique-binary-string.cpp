class Solution {
private:
    int n;
    string generate(string curr, unordered_set<string>& nums){
        if (curr.size() == n){
            if (!nums.count(curr))
                return curr;
            return "";
        }
        
        string addZero = generate(curr + "0", nums);
        if (!addZero.empty())
            return addZero;
        return generate(curr + "1", nums);
    }
    
public:
    string findDifferentBinaryString(vector<string>& nums) {
        n = nums.size();
        unordered_set<string> numsList(nums.begin(), nums.end());
        
        return generate("", numsList);
    }
};