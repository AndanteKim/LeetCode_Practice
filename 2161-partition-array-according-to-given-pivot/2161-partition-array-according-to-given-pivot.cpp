class Solution {
private:
    void merge(vector<int>& ans, queue<int>& elems){
        while(!elems.empty()){
            ans.push_back(elems.front());
            elems.pop();
        }
    }

public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        queue<int> left, center, right;

        for (int num : nums){
            if (num == pivot)
                center.push(num);
            else if (num < pivot)
                left.push(num);
            else
                right.push(num);
        }

        vector<int> ans;

        merge(ans, left);
        merge(ans, center);
        merge(ans, right);
        return ans;
    }
};