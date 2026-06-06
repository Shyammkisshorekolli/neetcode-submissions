class MinStack {
public:
    stack<int>st;
    stack<int>minstack;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minstack.empty()){
            minstack.push(val);
        }
        else{
            minstack.push(min(val,minstack.top()));
        }
    }
    
    void pop() {
        st.pop();
        minstack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
