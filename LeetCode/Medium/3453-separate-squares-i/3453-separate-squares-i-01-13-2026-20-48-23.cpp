class Solution {
private:
    int maxY = 0;
    long long totalArea = 0;
    
    bool check(double limitY, vector<vector<int>>& squares) {
        double area = 0.0;

        for (const auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];

            if (y < limitY) {
                area += l * min(limitY - y, (double)l);
            }
        }

        return area * 2 >= totalArea;
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        
        for (const auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            totalArea += (long long)l * l;
            maxY = max(maxY, y + l);
        }

        double lo = 0.0, hi = maxY, eps = 1e-5;

        while (abs(hi - lo) > eps) {
            double mid = (lo + hi) / 2;
            if (check(mid, squares)) hi = mid;
            else lo = mid;
        }

        return hi;
    }
};