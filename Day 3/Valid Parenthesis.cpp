class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(')s1.push('(');
            else if(s[i]==')'){
                if(s1.size()==0 || s1.top()!='(')return false;
                s1.pop();
            }
            else if(s[i]=='{')s1.push('{');
            else if(s[i]=='}'){
                 if(s1.size()==0 || s1.top()!='{')return false;
                s1.pop();
            }
            else if(s[i]=='[')s1.push('[');
            else if(s[i]==']'){
                 if(s1.size()==0 || s1.top()!='[')return false;
                s1.pop();
            }
        }
     return !s1.size();
    }
};