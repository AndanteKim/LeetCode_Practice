class SparseVector {
private:
    vector<int> nums1;

public:
    
    SparseVector(vector<int> &nums) {
        nums1 = nums;
    }

    vector<int> getCurrVector(){
        return nums1;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        vector<int> nums2 = vec.getCurrVector();
        int ans = 0, m = nums1.size(), n = nums2.size();
        if (m != n) return -1;
        
        for (int i = 0; i < m; ++i) ans += nums1[i] * nums2[i];
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);