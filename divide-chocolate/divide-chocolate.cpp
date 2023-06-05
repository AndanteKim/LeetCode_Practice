class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int n = k + 1;
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0) / n;
        
        while (left < right){
            int mid = (left + right + 1) / 2, currSweetness = 0, pplWithChocolate = 0;
            for (int s : sweetness){
                currSweetness += s;
                if (currSweetness >= mid){
                    ++pplWithChocolate;
                    currSweetness = 0;
                }
            }
            
            if (pplWithChocolate >= n) left = mid;
            else right = mid - 1;
        }
        
        return right;
    }
};