typedef long long ll;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> minHeap;
        
        // Count the frequency of each rank using a unordered_map
        unordered_map<int, int> count;
        for (int rank : ranks) ++count[rank];

        // Create a Min-heap storing [time, rank, n, count];
        // - time: time for the next repair
        // - rank: mechanic's rank
        // - n: cars repaired by this mechanic
        // - count: number of mechanics with this rank
        // Initial time = rank (as rank * 1 ^ 2 = rank)
        // Add initial entries to the heap
        for (const auto& [rank, mechanicCount] : count) minHeap.push({rank, rank, 1, mechanicCount});
        
        ll time = 0;

        // Process until all cars are repaired
        while (cars > 0){
            // Pop the mechanic with the smallest current repair time
            auto it = minHeap.top(); minHeap.pop();
            ll rank = it[1], n = it[2], freq = it[3];

            time = it[0];
            
            // Deduct the number of cars repaired by this mechanic group
            cars -= freq;

            // Increment the number of cars repaired by this mechanic
            ++n;

            // Push the updated repair time back into the heap
            // The new repair time is rank * n ^ 2 (since time increases quadratically with n)
            minHeap.push({rank * n * n, rank, n, freq});
        }

        return time;
    }
};