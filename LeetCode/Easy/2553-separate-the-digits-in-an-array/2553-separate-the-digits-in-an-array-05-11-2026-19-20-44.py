class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []

        for num in nums:
            st = []
            while num > 0:
                st.append(num % 10)
                num //= 10
            
            while st:
                ans.append(st.pop())

        return ans