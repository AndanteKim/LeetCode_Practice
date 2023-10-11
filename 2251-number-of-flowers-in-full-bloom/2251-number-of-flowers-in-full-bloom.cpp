class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        vector<int> sortedPeople(people.begin(), people.end());
        sort(sortedPeople.begin(), sortedPeople.end());
        vector<int> ans(people.size());
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> m;
        
        int i = 0;
        for (int t : sortedPeople){
            
            while (i < flowers.size() && flowers[i][0] <= t){
                pq.push(flowers[i][1]);
                ++i;
            }
            
            while (!pq.empty() && pq.top() < t)
                pq.pop();
            
            m[t] = pq.size();
        }
        
        for (int i = 0; i < people.size(); ++i)
            ans[i] = m[people[i]];
        
        return ans;
    }
};