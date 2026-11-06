class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        /*
            Create a stack to store numbers.

            Numbers are pushed into the stack.
            When an operator appears, we take the
            last two numbers and calculate the result.
        */
        stack<int> st;

        /*
            Traverse every token in the expression.
        */
        for (string token : tokens) {

            /*
                Check whether the current token is
                an arithmetic operator.
            */
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                /*
                    First pop gives the RIGHT operand.

                    Example:
                    Stack = [2, 1]

                    First pop = 1 (right operand)
                */
                int b = st.top();
                st.pop();

                /*
                    Second pop gives the LEFT operand.

                    Second pop = 2 (left operand)

                    Remember:
                    a operator b
                */
                int a = st.top();
                st.pop();

                /*
                    Perform the operation based on
                    the current operator.
                */
                int result = 0;

                if (token == "+") {
                    result = a + b;
                }

                else if (token == "-") {
                    result = a - b;
                }

                else if (token == "*") {
                    result = a * b;
                }

                else if (token == "/") {

                    /*
                        C++ integer division truncates
                        toward zero, as required by RPN.
                    */
                    result = a / b;
                }

                /*
                    Push the calculated result back
                    into the stack.

                    This result can be used by a
                    later operator.
                */
                st.push(result);
            }

            else {

                /*
                    If the token is not an operator,
                    it is a number.

                    Convert the string into an integer
                    and push it into the stack.

                    stoi() also handles negative numbers
                    such as "-11".
                */
                st.push(stoi(token));
            }
        }

        /*
            A valid RPN expression leaves exactly
            one final result in the stack.
        */
        return st.top();
    }
};