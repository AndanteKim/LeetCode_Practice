class Solution {
private:
    void looping(vector<int>& arr, vector<int>& countingSort){
        for (int num : arr)
            ++countingSort[num];
    }
    
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> countingSort(2001);
        
        looping(arr1, countingSort);
        looping(arr2, countingSort);
        looping(arr3, countingSort);
        
        vector<int> ans;
        
        for (int i = 1; i <= 2000; ++i)
            if (countingSort[i] == 3) ans.push_back(i);
        
        return ans;
    }
};