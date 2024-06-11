class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mx = *max_element(arr1.begin(), arr1.end());
        vector<int> countSort(mx + 1), ans;
        for (int e1 : arr1) ++countSort[e1];
        
        for (int e2 : arr2) {
            while (countSort[e2]-- > 0){
                ans.push_back(e2);
            }
        }
        
        for (int e = 0; e < countSort.size(); ++e){
            while (countSort[e]-- > 0)
                ans.push_back(e);
        }
        
        return ans;
    }
};