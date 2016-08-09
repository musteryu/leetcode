#include <queue>
using namespace std;

class Stack {
private:
    queue<int> data;
public:
    // Push element x onto stack.
    void push(int x) {
        queue<int> new_data;
        new_data.push(x);
        while (!data.empty()) {
            new_data.push(data.front());
            data.pop();
        }
        data = std::move(new_data);
    }

    // Removes the element on top of the stack.
    void pop() {
        data.pop();
    }

    // Get the top element.
    int top() {
        return data.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return data.empty();
    }
};