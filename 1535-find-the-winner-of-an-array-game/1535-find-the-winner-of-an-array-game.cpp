class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        queue<int> q({arr.begin(), arr.end()});
        int first = -1, second = -1, firstWin = 0, secondWin = 0;
        
        while (firstWin < k && secondWin < k){
            if (first == -1){
                first = q.front();
                q.pop();
            }
            if (second == -1){
                second = q.front();
                q.pop();
            }
            
            if (first > second){
                q.push(second);
                second = -1;
                ++firstWin;
                secondWin = 0;
            }
            else{
                q.push(first);
                first = -1;
                ++secondWin;
                firstWin = 0;
            }
            
            if (firstWin > arr.size() || secondWin > arr.size())
                break;
        }
        
        return first != -1? first : second;
    }
};