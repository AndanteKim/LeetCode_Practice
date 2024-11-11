First wrong: 2024-11-11
​
Review from here. vokasi_olvap's solution from binary search
​
prime = [True for i in range(1000 + 1)] # !!! this is cached for all test runs !!!
i = 2
while i * i < 1000 + 1:
for p in range(i * i, 1000 + 1, i):
prime[p] = False
i += 1
prime = [p for p in range(2, 1000 + 1) if prime[p]]
​
class Solution:
def primeSubOperation(self, nums: List[int]) -> bool:
N = len(nums)
P = len(prime)
for i in reversed(range(N - 1)):
if nums[i] >= nums[i + 1]:
left = bisect_right(prime, nums[i] - nums[i + 1])
if left == P: # cannot find non-dupe prime (nums = [1000],3, prime=997 will create dupe)
return False
nums[i] -= prime[left]
if nums[i] <= 0: # 0 means prime == target or prime > target
return False
return True