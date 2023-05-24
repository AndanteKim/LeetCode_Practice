typedef long long ll;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums1.size(); ++i) pairs.push_back({nums1[i], nums2[i]});
        sort(pairs.begin(), pairs.end(), [](pair<int, int>& a, pair<int, int>& b){return a.second > b.second;});
        
        priority_queue<int, vector<int>, greater<int>> top_k_heap;
        ll top_k_sum = 0;
        for (int i = 0; i < k; ++i) {
            top_k_sum += pairs[i].first;
            top_k_heap.push(pairs[i].first);
        }
        ll answer = top_k_sum * pairs[k - 1].second, curr;
        
        for (int i = k; i < pairs.size(); ++i){
            top_k_sum -= top_k_heap.top();
            top_k_heap.pop();
            top_k_sum += pairs[i].first;
            top_k_heap.push(pairs[i].first);
            curr = top_k_sum * pairs[i].second;
            answer = max(answer, curr);
        }
        
        return answer;
    }
};