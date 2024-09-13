class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        # Prefix sum
        n = len(arr)
        prefix_xor = [0] * (n + 1)
        
        for i in range(n):
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i]
            
        ans = []
        for left, right in queries:
            ans.append(prefix_xor[right + 1] ^ prefix_xor[left])
        
        return ans