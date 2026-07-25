class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> maxHeap;

        while (n > 0) {
            maxHeap.push(n % 10);
            n /= 10;
        }

        int b1 = maxHeap.top(); maxHeap.pop();
        int b2 = maxHeap.top(); maxHeap.pop();

        return b1 * b2;
    }
};