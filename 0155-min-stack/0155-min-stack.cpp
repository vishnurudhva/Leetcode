class MinStack {
public:
    vector<int> stack;
    vector<int> minStk;
    MinStack() {
        
    }
    
    void push(int val) {
        if (minStk.size() == 0 || val <= minStk.back()) minStk.push_back(val); 
        stack.push_back(val);
    }
    
    void pop() {
        if (minStk.size() > 0 && top() == minStk.back()) minStk.pop_back(); 
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minStk.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */