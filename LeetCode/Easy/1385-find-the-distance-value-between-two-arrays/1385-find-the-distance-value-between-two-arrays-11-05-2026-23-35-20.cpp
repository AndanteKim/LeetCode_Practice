class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ans = 0;

        for (auto& a1 : arr1) {
            unsigned p = lower_bound(arr2.begin(), arr2.end(), a1) - arr2.begin();
            bool ok = true;

            if (p < arr2.size()) ok &= (arr2[p] - a1 > d);

            if (p - 1 >= 0 && p - 1 <= arr2.size()) ok &= (a1 - arr2[p - 1] > d);
            ans += ok;
        }

        return ans;
    }
};