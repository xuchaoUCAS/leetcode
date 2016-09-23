class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        while(q.size() - 1){
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }

    // Get the top element.
    int top() {
        return q.back();
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty() && temp.empty();
    }
private:
    queue<int> q, temp;
};