#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int num = num1; num <= num2; ++num) {
            // Use a vector to store digits mapped by index (replaces Python dict)
            // Max digits for int is around 10, so 20 is safe padding.
            vector<int> mapping(20); 
            int n = 0;
            int tempNum = num;

            // Min-heap to store pairs of (digit, index)
            // std::greater makes it a min-heap based on the first element (digit)
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            while (tempNum > 0) {
                int digit = tempNum % 10;
                pq.push({digit, n});
                mapping[n] = digit;
                tempNum /= 10;
                n++;
            }

            // Process the heap
            while (!pq.empty()) {
                pair<int, int> top = pq.top();
                pq.pop();
                
                int digit = top.first;
                int idx = top.second;

                // Skip first and last indices
                if (idx == 0 || idx == n - 1) {
                    continue;
                }

                int prevDigit = mapping[idx - 1];
                int nextDigit = mapping[idx + 1];

                // Check for waviness (local peak or valley)
                bool isValley = (prevDigit > digit && digit < nextDigit);
                bool isPeak = (prevDigit < digit && digit > nextDigit);

                if (isValley || isPeak) {
                    ans++;
                }
            }
        }

        return ans;
    }
};