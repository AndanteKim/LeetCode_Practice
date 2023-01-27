class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> lookup(arr.begin(), arr.end());
        int cnt = 0;
        for (const int& num : arr){
            if (lookup.find(num) != lookup.end() && lookup.find(num+1) != lookup.end()) ++cnt;
        }
        
        return cnt;
    }
};