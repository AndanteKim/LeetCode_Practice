class Solution {
    void bucketSort(vector<int>& arr, int placeValue){
        vector<vector<int>> buckets(10, vector<int>());
        
        for (int& val : arr){
            int digit = abs(val) / placeValue;
            digit %= 10;
            buckets[digit].push_back(val);
        }
        
        int index = 0;
        for (int digit = 0; digit < 10; ++digit){
            for (int& val : buckets[digit]){
                arr[index] = val;
                ++index;
            }
        }
    }
    
    void radixSort(vector<int>& arr){
        int maxElement = arr[0];
        for (int& val : arr) maxElement = max(abs(val), maxElement);
        int maxDigits = 0;
        while (maxElement > 0){
            ++maxDigits;
            maxElement /= 10;
        }
        
        int placeValue = 1;
        for (int digit = 0; digit < maxDigits; ++digit){
            bucketSort(arr, placeValue);
            placeValue *= 10;
        }
        
        vector<int> negatives, positives;
        for (int& val : arr){
            if (val < 0) negatives.push_back(val);
            else positives.push_back(val);
        }
        reverse(negatives.begin(), negatives.end());
        merge(negatives.begin(), negatives.end(), positives.begin(), positives.end(), arr.begin());
    }

    
public:
    vector<int> sortArray(vector<int>& nums) {
        radixSort(nums);
        return nums;
    }
};