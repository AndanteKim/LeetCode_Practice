class Logger {
    unordered_map<string, int> logs;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (logs.find(message) == logs.end()) {
            logs[message] = timestamp;
            return true;
        }
        
        if (timestamp - logs[message] >= 10){
            logs[message] = timestamp;
            return true;
        }
        else return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */