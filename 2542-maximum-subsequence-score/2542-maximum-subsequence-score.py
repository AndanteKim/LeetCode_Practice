class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        # sort pair (nums1[i], nums2[i]) in decresing order
        n = len(nums1)
        pairs = [(nums1[i], nums2[i]) for i in range(n)]
        pairs.sort(key = lambda x: -x[1])
        
        # use a min-heap to maintain the top k elements
        top_k_heap = [x[0] for x in pairs[:k]]
        top_k_sum = sum(top_k_heap)
        heapify(top_k_heap)
        
        # The score of the first k pairs
        ans = top_k_sum * pairs[k - 1][1]
        
        # iterate over every nums2[i] as minimum from nums2
        for i in range(k, n):
            # remove the smallest integer from the previous top k elements
            top_k_sum -= heappop(top_k_heap)
            top_k_sum += pairs[i][0]
            heappush(top_k_heap, pairs[i][0])
            
            # update answer
            ans = max(ans, top_k_sum * pairs[i][1])
            
        return ans