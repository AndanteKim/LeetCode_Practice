class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        n = len(arr)
        prefix_xor = [0] * (n + 1)
        
        # Build prefix XOR array
        for i in range(n):
            prefix_xor[i + 1] = prefix_xor[i] ^ arr[i]
            
        ans = []
        # Process each query using prefix XOR
        for left, right in queries:
            ans.append(prefix_xor[right + 1] ^ prefix_xor[left])
        
        return ans