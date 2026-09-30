class Solution {
public:
    int operate(int a, int b, string token)
    {
        if(token == "+")
        {
            return a + b;
        }
        else if(token == "-")
        {
            return a - b;
        }
        else if(token == "*")
        {
            return a * b;
        }
        else if(token == "/")
        {
            return a / b;
        }

        return -1;
    }

    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" ||
               tokens[i] == "*" || tokens[i] == "/")
            {
                // First popped = right operand
                int n1 = st.top();
                st.pop();

                // Second popped = left operand
                int n2 = st.top();
                st.pop();

                // Calculate left operator right
                int res = operate(n2, n1, tokens[i]);

                st.push(res);
            }
            else
            {
                // Push number
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};