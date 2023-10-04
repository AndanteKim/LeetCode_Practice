typedef long long ll;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        int n = nums1.size();
        for (int i = 0; i < n; ++i)
            pairs.push_back({nums1[i], nums2[i]});
        sort(pairs.begin(), pairs.end(), [](auto& a, auto& b) {return a.second > b.second;});
        
        // set min heap to pop min value of nums1 between 0 ~ k - 1
        priority_queue<int, vector<int>, greater<int>> topKHeap;
        ll topKSum = 0, ans = 0;
        for (int i = 0; i < k; ++i){
            topKHeap.push(pairs[i].first);
            topKSum += pairs[i].first;
        }
        
        ans = topKSum * pairs[k - 1].second;
        
        for (int i = k; i < n; ++i){
            topKSum -= topKHeap.top();
            topKHeap.pop();
            topKSum += pairs[i].first;
            topKHeap.push(pairs[i].first);
            ans = max(ans, topKSum * pairs[i].second);
        }
        
        return ans;
    }
};