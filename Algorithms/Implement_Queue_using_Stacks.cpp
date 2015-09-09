class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!stk[1].empty()) {
            stk[0].push(stk[1].top());
            stk[1].pop();
        }
        stk[0].push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!stk[0].empty()) {
            stk[1].push(stk[0].top());
            stk[0].pop();
        }
        stk[1].pop();
    }

    // Get the front element.
    int peek(void) {
        while (!stk[0].empty()) {
            stk[1].push(stk[0].top());
            stk[0].pop();
        }
        return stk[1].top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk[0].empty() && stk[1].empty();
    }
private:
    stack<int> stk[2];
};
