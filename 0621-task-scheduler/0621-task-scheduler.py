class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Counter array to store the frequency of each task
        counter = [0] * 26
        max_val, max_count = 0, 0
        
        # Traverse through tasks to calculate task frequencies
        for task in tasks:
            counter[ord(task) - 65] += 1
            if max_val == counter[ord(task) - 65]:
                max_count += 1
            elif max_val < counter[ord(task) - 65]:
                max_val = counter[ord(task) - 65]
                max_count = 1
        
        # Calculate idle slots, available, taasks, and idles needed
        part_count = max_val - 1
        part_length = n - (max_count - 1)
        empty_slots = part_count * part_length
        available_tasks = len(tasks) - max_val * max_count
        idles = max(0, empty_slots - available_tasks)
        
        # Return the total time required
        return len(tasks) + idles