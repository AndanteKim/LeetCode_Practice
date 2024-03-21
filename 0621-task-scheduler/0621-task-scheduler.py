class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # freq array to store the frequency of each task
        freq, max_count = [0] * 26, 0
        
        # Count the frequency of each task and find the maximum frequency
        for task in tasks:
            freq[ord(task) - 65] += 1
            max_count = max(max_count, freq[ord(task) - 65])
        
        # Calculate the total time needed for execution
        time = (max_count - 1) * (n + 1)
        for f in freq:
            if f == max_count:
                time += 1
        
        # Return the maximum of total time needed and the length of the task list
        return max(len(tasks), time)