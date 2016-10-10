public class Logger {
    Map<String, Integer> msgTime;
    /** Initialize your data structure here. */
    public Logger() {
        msgTime = new HashMap<>();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    public boolean shouldPrintMessage(int timestamp, String message) {
        if (!msgTime.containsKey(message)) {
            msgTime.put(message, timestamp);
            return true;
        }
        int lastTime = msgTime.get(message);
        if (timestamp - lastTime < 10)
            return false;
        msgTime.put(message, timestamp);
        return true;
    }
}

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * boolean param_1 = obj.shouldPrintMessage(timestamp,message);
 */