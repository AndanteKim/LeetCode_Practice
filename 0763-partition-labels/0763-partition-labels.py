class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # Stores the last index of each character in 's'
        last_occurrence = [0] * 26

        for i, ch in enumerate(s):
            last_occurrence[ord(ch) - 97] = i

        partition_end, partition_start = 0, 0
        ans = []

        for i, ch in enumerate(s):
            partition_end = max(partition_end, last_occurrence[ord(ch) - 97])

            # End of the current partition
            if i == partition_end:
                ans.append(i - partition_start + 1)
                partition_start = i + 1

        return ans