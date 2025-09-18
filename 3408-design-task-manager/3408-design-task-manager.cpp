class TaskManager {
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    unordered_map<int, int> taskPriority, taskOwner;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const vector<int>& task : tasks)
            add(task[0], task[1], task[2]);
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        taskPriority[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskPriority[taskId] = -1;
    }
    
    int execTop() {
        while (!pq.empty()){
            const auto [priority, taskId] = pq.top(); pq.pop();            

            if (taskPriority[taskId] == priority) {
                taskPriority[taskId] = -1;
                return taskOwner[taskId];
            }

        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */