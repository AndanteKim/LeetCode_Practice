class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<double> seen;
        
        for (int num : arr){
            if (seen.count(num / 2.0) || seen.count(num * 2))
                return true;
            seen.insert(num);
        }
        
        return false;
    }
};