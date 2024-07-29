#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        s += '+';
        stack<int> stk;
        
        long long int result = 0, currentNumber = 0;
        char previousOperator = '+';
        
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                currentNumber = currentNumber * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if (previousOperator == '+') {
                    stk.push(currentNumber);
                } else if (previousOperator == '-') {
                    stk.push(currentNumber * (-1));
                } else if (previousOperator == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * currentNumber);
                } else if (previousOperator == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / currentNumber);
                }
                
                currentNumber = 0;
                previousOperator = s[i];
            }
        }
        
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        
        return result;
    }
};
