class Solution {
private:
    int n;
    unordered_set<string> candidates;
    string backtrack(string curr) {
        if (curr.size() == n) {
            if (!candidates.contains(curr)) return curr;
            return "";
        }

        string addZero = backtrack(curr + "0");
        if (!addZero.empty()) return addZero;

        return backtrack(curr + "1");
    }

public:
    string findDifferentBinaryString(vector<string>& nums) {
        this -> n = nums.size();
        for (const string& num : nums) candidates.insert(num);
        return backtrack("");
    }
};