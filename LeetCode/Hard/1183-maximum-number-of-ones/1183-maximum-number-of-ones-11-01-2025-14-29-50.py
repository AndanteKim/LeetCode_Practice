class Solution:
    def maximumNumberOfOnes(self, width: int, height: int, sideLength: int, maxOnes: int) -> int:
        ans = maxOnes * ((height // sideLength) * (width // sideLength))
        remain = maxOnes

        cnt1 = min((height % sideLength) * (width % sideLength), remain)
        ans += ((height // sideLength) + (width // sideLength) + 1) * cnt1
        remain -= cnt1

        if height // sideLength > width // sideLength:
            cnt2 = min(((width % sideLength) * sideLength) - ((height % sideLength) * (width % sideLength)), remain)
            ans += (height // sideLength) * cnt2
            remain -= cnt2
            
            cnt3 = min(((height % sideLength) * sideLength) - ((height % sideLength) * (width % sideLength)), remain)
            ans += (width // sideLength) * cnt3
            remain -= cnt3
        else:
            cnt2 = min(((height % sideLength) * sideLength) - ((height % sideLength) * (width % sideLength)), remain)
            ans += (width // sideLength) * cnt2
            remain -= cnt2
            
            cnt3 = min(((width % sideLength) * sideLength) - ((height % sideLength) * (width % sideLength)), remain)
            ans += (height // sideLength) * cnt3
            remain -= cnt3

        return ans