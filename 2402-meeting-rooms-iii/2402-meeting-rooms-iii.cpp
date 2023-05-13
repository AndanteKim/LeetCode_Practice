typedef long long ll;
class Solution {
    
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> ready;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll,int>>> rooms;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ready.push(i);
        
        for (vector<int>& meeting : meetings){
            int r;
            while (!rooms.empty() && rooms.top().first <= meeting[0]){
                ll t = rooms.top().first;
                r = rooms.top().second;
                rooms.pop();
                ready.push(r);
            }
            if (!ready.empty()){
                r = ready.top();
                ready.pop();
                rooms.push({meeting[1], r});
                
            }
            else{
                ll t = rooms.top().first;
                r = rooms.top().second;
                rooms.pop();
                rooms.push({t + meeting[1] - meeting[0], r});
            }
            
            ++ans[r];
        }
        
        return max_element(ans.begin(), ans.end()) - ans.begin();
    }
};