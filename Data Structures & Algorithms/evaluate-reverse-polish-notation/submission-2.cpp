class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(auto &c:tokens){
            if(c!="+"&&c!="*"&&c!="/"&&c!="-") s.push(stoi(c));
            else{
                if(c=="+"){
                    int x=s.top();
                    s.pop();
                    int y=s.top();
                    s.pop();
                    int z=x+y;
                    s.push(z);
                }
                else if(c=="-"){
                    int x=s.top();
                    s.pop();
                    int y=s.top();
                    s.pop();
                    int z=y-x;
                    s.push(z);
                }
                else if(c=="*"){
                    int x=s.top();
                    s.pop();
                    int y=s.top();
                    s.pop();
                    int z=x*y;
                    s.push(z);
                }
                else if(c=="/"){
                    int x=s.top();
                    s.pop();
                    int y=s.top();
                    s.pop();
                    int z=y/x;
                    s.push(z);
                }
            }
            
        }
        return s.top();
    }
};
