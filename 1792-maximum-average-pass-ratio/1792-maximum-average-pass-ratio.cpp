class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size(), numerator, denominator;
        double ratio, nextRatio;
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>> minHeap;

        for (int i = 0; i < n; ++i){
            numerator = classes[i][0], denominator = classes[i][1];
            nextRatio = (double)(numerator + 1) / (denominator + 1);
            ratio = (double)numerator / denominator;
            minHeap.push({nextRatio - ratio, numerator, denominator});
        }

        for (int i = 0; i < extraStudents; ++i){
            auto [_, numerator, denominator] = minHeap.top(); minHeap.pop();
            ++numerator, ++denominator;
            nextRatio = (double)(numerator + 1) / (denominator + 1);
            ratio = (double)numerator / denominator;
            minHeap.push({nextRatio - ratio, numerator, denominator});
        }

        double totalAverage = 0.0;
        while (!minHeap.empty()){
            auto [_, numerator, denominator] = minHeap.top(); minHeap.pop();
            totalAverage += (double)numerator / denominator;
        }

        return totalAverage / n;
    }
};