class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.length();
        for(auto &c:s){
            if(c=='('||c=='{'||c=='['){
                st.push(c);
            }
            else{
                if(st.empty()) return false;
                if(st.top()!='(' && c==')') return false;
                if(st.top()!='{' && c=='}') return false;
                if(st.top()!='[' && c==']') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
