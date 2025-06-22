class MinQueue{
private:
    deque<int> mins, q;

public:
    void push(int x){
        q.push_back(x);
        while (!mins.empty() && x < mins.back()) mins.pop_back();
        mins.push_back(x);
    }

    void pop(){
        if (!q.empty()){
            int x = q.front(); q.pop_front();
            if (mins.front() == x) mins.pop_front();
        }
    }

    int getMin() const{
        return mins.front();
    }
};

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> days(n);

        // Map to bulbs position
        for (int day = 1; day < n; ++day) days[bulbs[day] - 1] = day + 1;

        MinQueue window;
        int ans = n;

        for (int i = 0; i < n; ++i){
            window.push(days[i]);
            if (k <= i && i < n - 1){
                window.pop();
                if (k == 0 || (days[i - k] < window.getMin() && window.getMin() > days[i + 1]))
                    ans = min(ans, max(days[i - k], days[i + 1]));
            }
        }

        return (ans < n)? ans : -1;
    }
};