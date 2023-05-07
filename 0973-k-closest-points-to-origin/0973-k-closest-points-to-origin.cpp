class Solution {
    int dist(vector<int>& point){
        return point[0] * point[0] + point[1] * point[1];
    }
    
    void quicksort(int i, int j, int K, vector<vector<int>>& points){
        if (i >= j) return;
        int k = (rand() % (j - i)) + i;
        swap(points[i], points[k]);
        
        int mid = partition(i, j, points);
        if (K < mid - i + 1) quicksort(i, mid - 1, K, points);
        else if (K > mid - i + 1) quicksort(mid + 1, j, K - (mid - i + 1), points);
    }
    
    int partition(int i, int j, vector<vector<int>>& points){
        int oi = i, pivot = dist(points[i]);
        ++i;
        
        while (true){
            while ((i < j) && (dist(points[i]) < pivot)) ++i;
            while ((i <= j) && (dist(points[j]) >= pivot)) --j;
            if (i >= j) break;
            swap(points[i], points[j]);
        }
        swap(points[oi], points[j]);
        return j;
    }
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> ans;
        quicksort(0, n - 1, k, points);
        for (int i = 0; i < k; ++i) ans.push_back(points[i]);
        
        return ans;
    }
};