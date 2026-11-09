class MyQueue {
private:
    // Stores newly inserted elements.
    stack<int> inStack;

    // Provides elements in FIFO order.
    stack<int> outStack;

    // Move elements only when the output stack is empty.
    void transfer() {

        if (outStack.empty()) {

            // Reverse the order of elements.
            while (!inStack.empty()) {

                // Take the top element from the input stack.
                outStack.push(inStack.top());

                // Remove it from the input stack.
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {

        // Add the new element to the input stack.
        inStack.push(x);
    }

    int pop() {

        // Make sure the oldest element is on top.
        transfer();

        // Save and remove the front element.
        int front = outStack.top();
        outStack.pop();

        return front;
    }

    int peek() {

        // Make sure the oldest element is on top.
        transfer();

        // Return the front without removing it.
        return outStack.top();
    }

    bool empty() {

        // The queue is empty only if both stacks are empty.
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */