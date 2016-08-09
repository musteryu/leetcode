class MinStack {
private:
    std::vector<int> data_;
    std::vector<int> mins_;
public:
    MinStack(){
        
    }
    
    void push(int x) {
        data_.push_back(x);
        mins_.push_back(mins_.empty() ? x : std::min(x, mins_.back()));
    }
    
    void pop() {
        data_.pop_back();
        mins_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() {
        return mins_.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

// Leetcode does not support C++ 11
class MinStack
{
public:
    std::forward_list<int> data_;
    std::forward_list<int> mins_;
    MinStack() {};

    void push(int x) {
        data_.push_front(x);
        mins_.push_front(mins_._empty() ? x : std::min(x, mins_.front()));
    }

    void pop() {
        data_.pop_front();
        mins_.pop_front();
    }

    int top() {
        return data_.front();
    }

    int getMin() {
        return mins_.front();
    }
};
