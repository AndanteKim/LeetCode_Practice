class Solution {
private:
    int n, k;

    bool isPossible(double D, vector<int>& stations){
        int installed = 0;

        for (int i = 0; i < n - 1; ++i)
            installed += (int)((stations[i + 1] - stations[i]) / D);

        return installed <= k;
    }

public:
    double minmaxGasDist(vector<int>& stations, int k) {
        this -> n = stations.size();
        this -> k = k;

        double lo = 0, hi = 100'000'000, mid;
        while ((hi - lo) > 1e-6){
            mid = (lo + hi) / 2.0;

            if (isPossible(mid, stations)) hi = mid;
            else lo = mid;
        }

        return lo;
    }
};