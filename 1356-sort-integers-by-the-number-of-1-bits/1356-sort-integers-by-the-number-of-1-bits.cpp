class Solution {
    struct comparison{
        inline bool operator()(int a, int b){
            int bin_a_cnt1 = 0, bin_b_cnt1 = 0, a_cp = a, b_cp = b;
        
            while (a_cp > 0){
                a_cp % 2 == 1? ++bin_a_cnt1 : bin_a_cnt1 += 0;
                a_cp >>= 1;
            }
        
            while (b_cp > 0){
                b_cp % 2 == 1? ++bin_b_cnt1 : bin_b_cnt1 += 0;
                b_cp >>= 1;
            }
            
            return bin_a_cnt1 < bin_b_cnt1? bin_a_cnt1 < bin_b_cnt1 : bin_a_cnt1 == bin_b_cnt1 ? a < b : bin_b_cnt1 > bin_a_cnt1;
        }
    };
    
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comparison());
        return arr;
    }
};