class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        ans = []
        first_occurrence, last_occurrence = [-1] * 26, [0] * 26
        partition_start, partition_end = 0, 0

        # Store the last occurrence index of each character
        for i, ch in enumerate(s):
            last_occurrence[ord(ch) - 97] = i

        for i, ch in enumerate(s):
            idx = ord(ch) - 97

            # Store the first occurrence index of each character (if not set)
            if first_occurrence[idx] == -1:
                first_occurrence[idx] = i

            # If we find a new partition start
            if partition_end < first_occurrence[idx]:
                ans.append(partition_end - partition_start + 1)
                partition_start, partition_end = i, i

            # Update partition end boundary
            partition_end = max(partition_end, last_occurrence[idx])

        # Add the last partition if it exists
        if partition_end - partition_start + 1 > 0:
            ans.append(partition_end - partition_start + 1)

        return ans