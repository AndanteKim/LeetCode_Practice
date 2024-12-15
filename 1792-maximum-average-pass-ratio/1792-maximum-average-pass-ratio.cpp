class Solution {
private:
    // Lambda to calculate the gain of adding an extra student
    double calculateGain(int passes, int totalStudents){
        return (double)(passes + 1) / (totalStudents + 1) - ((double)passes / totalStudents);
    }
    
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max heap to store (-gain, passes, total_students)
        priority_queue<tuple<double, int, int>> maxHeap;
        int n = classes.size();
        for (int i = 0; i < n; ++i){
            int passes = classes[i][0], totalStudents = classes[i][1];
            double gain = calculateGain(passes, totalStudents);
            maxHeap.push({gain, passes, totalStudents});
        }
        
        // Distribute extra students
        for (int i = 0; i < extraStudents; ++i){
            auto [_, passes, totalStudents] = maxHeap.top(); maxHeap.pop();
            double gain = calculateGain(passes + 1, totalStudents + 1);
            maxHeap.push({gain, passes + 1, totalStudents + 1});
        }
        
        // Calculate the final average pass ratio
        double totalPassRatio = 0.0;
        while (!maxHeap.empty()){
            auto [_, passes, totalStudents] = maxHeap.top(); maxHeap.pop();
            totalPassRatio += (double)passes / totalStudents;
        }
        
        return totalPassRatio / n;
    }
};