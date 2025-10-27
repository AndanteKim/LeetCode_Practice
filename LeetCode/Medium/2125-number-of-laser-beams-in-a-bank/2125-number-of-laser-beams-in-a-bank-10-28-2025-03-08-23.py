class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        m, n = len(bank), len(bank[0])
        ans, devices_count = 0, []

        for i in range(m):
            curr = 0
            
            for dev in bank[i]:
                curr += int(dev)

            if curr > 0:
                devices_count.append(curr)

        for i in range(len(devices_count) - 1):
            ans += devices_count[i] * devices_count[i + 1]

        return ans