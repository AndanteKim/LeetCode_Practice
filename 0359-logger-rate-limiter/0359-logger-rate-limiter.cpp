class Logger {
    set<string> msg_set;
    queue<pair<string, int>> msg_queue;
    
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        while (!msg_queue.empty()){
            auto elem = msg_queue.front();
            string msg = elem.first;
            int ts = elem.second;
            if (timestamp - ts >= 10){
                msg_queue.pop();
                msg_set.erase(msg);
            }
            else break;
        }
        
        if (msg_set.find(message) == msg_set.end()){
            msg_set.insert(message);
            msg_queue.push({message, timestamp});
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */