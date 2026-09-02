class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        n = len(nums1)
        
        # All odd
        all_odd = True
        for i in range(n):
            if nums1[i] % 2:
                continue
            
            odd_detected = False
            for j in range(n):
                if i == j:
                    continue

                if (nums1[i] - nums1[j]) % 2:
                    odd_detected = True
                    break
            
            if not odd_detected:
                all_odd = False
                break

        # All even
        all_even = True
        for i in range(n):
            if nums1[i] % 2 == 0:
                continue
            
            even_detected = False
            for j in range(n):
                if i == j:
                    continue
                
                if (nums1[i] - nums1[j]) % 2 == 0:
                    even_detected = True
                    break
            
            if not even_detected:
                all_even = False
                break

        return all_odd or all_even