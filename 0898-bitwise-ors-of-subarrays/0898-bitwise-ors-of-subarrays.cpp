class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans, curr;

        for (int num : arr){
            unordered_set<int> curr2;
            curr2.insert(num);
            for (int y : curr) curr2.insert(num | y);
            ans.insert(curr2.begin(), curr2.end());
            curr = curr2;
        }

        return ans.size();
    }
};