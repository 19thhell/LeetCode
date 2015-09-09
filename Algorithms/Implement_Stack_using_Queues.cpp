class Stack {
public:
    Stack() : index(0) {}
    
    // Push element x onto stack.
    void push(int x) {
        int prev = index;
        index = 1 - index;
        q[index].push(x);
        while (!q[prev].empty()) {
            q[index].push(q[prev].front());
            q[prev].pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q[index].pop();
    }

    // Get the top element.
    int top() {
        return q[index].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[index].empty();
    }
private:
    queue<int> q[2];
    int index;
};
