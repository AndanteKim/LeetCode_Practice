class Solution {
private:
    int computing(int start, vector<int>& countSort){
        int count = 0, product = 1;
        
        if (start == 0){
            for (int i = 0; i < countSort.size() && count < 2; ++i){
                while (countSort[i] && count < 2){
                    product *= i;
                    --countSort[i];
                    ++count;
                }
            }
        }
        else{
            for (int i = countSort.size() - 1; i >= 1 && count < 2; --i){
                while (countSort[i] && count < 2){
                    product *= i;
                    --countSort[i];
                    ++count;
                }
            }
        }
        
        return product;
    }
    
public:
    int maxProductDifference(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> countSort(maxNum + 1);
        for (int num : nums)
            ++countSort[num];
        int maxPair = computing(maxNum, countSort), minPair = computing(0, countSort);
        cout << maxPair << endl;
        cout << minPair << endl;
        return maxPair - minPair;
    }
};