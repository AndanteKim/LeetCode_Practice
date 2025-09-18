class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.pq = []
        self.task_priority, self.task_owner = dict(), dict()

        for user_id, task_id, priority in tasks:
            self.add(user_id, task_id, priority)

    def add(self, userId: int, taskId: int, priority: int) -> None:
        heappush(self.pq, (-priority, -taskId))
        self.task_priority[taskId] = priority
        self.task_owner[taskId] = userId

    def edit(self, taskId: int, newPriority: int) -> None:
        heappush(self.pq, (-newPriority, -taskId))
        self.task_priority[taskId] = newPriority

    def rmv(self, taskId: int) -> None:
        self.task_priority[taskId] = -1

    def execTop(self) -> int:
        while self.pq:
            neg_p, neg_t_id = heappop(self.pq)
            priority, t_id = -neg_p, -neg_t_id
            if self.task_priority.get(t_id, -2) == priority:
                self.task_priority[t_id] = -1
                return self.task_owner.get(t_id, -1)
        return -1


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()