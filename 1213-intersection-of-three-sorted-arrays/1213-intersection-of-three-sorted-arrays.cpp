class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        
        // Prepare three pointers to iterate through three arrays
        // p1, p2, and p3 point to the beginning of arr1, arr2, and arr3 accordingly
        int p1 = 0, p2 = 0, p3 = 0;
        
        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()){
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]){
                ans.push_back(arr1[p1]);
                ++p1; ++p2; ++p3;
            }
            else{
                if (arr1[p1] < arr2[p2])
                    ++p1;
                else if (arr2[p2] < arr3[p3])
                    ++p2;
                else
                    ++p3;
            }
        }
        
        return ans;
    }
};