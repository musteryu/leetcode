#include <stack>
using namespace std;

class Queue {
private:
    stack<int> data;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> new_data;
        while (!data.empty()) {
            new_data.push(data.top());
            data.pop();
        }
        new_data.push(x);
        while (!new_data.empty()) {
            data.push(new_data.top());
            new_data.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        data.pop();
    }

    // Get the front element.
    int peek(void) {
        return data.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return data.empty();
    }
};