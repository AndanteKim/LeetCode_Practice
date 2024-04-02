class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i){
            int left = i + 1, right = numbers.size() - 1, second = target - numbers[i];
            
            while (left <= right){
                int mid = left + ((right - left) >> 1);
                if (numbers[mid] < second) left = mid + 1;
                else if (numbers[mid] > second) right = mid - 1;
                else
                    return {i + 1, mid + 1};
            }
        }
        
        return {};
    }
};