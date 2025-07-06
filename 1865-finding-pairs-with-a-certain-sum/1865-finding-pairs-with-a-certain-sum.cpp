class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        for (int num : nums2) ++freq2[num];
    }
    
    void add(int index, int val) {
        --freq2[nums2[index]];
        nums2[index] += val;
        ++freq2[nums2[index]];
    }
    
    int count(int tot) {
        int pairs = 0;
        for (int i = 0; i < nums1.size(); ++i){
            int target = tot - nums1[i];
            pairs += freq2[target];
        }

        return pairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */