#include "expression.h"

expression::expression()
{}

int priority(char c)
{
    if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

std::string infixToPostfix(std::string infix)
{
    std::stack<char> st;
    std::string postfix;

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ')
            continue;
        if (infix[i] >= 'a' && infix[i] <= 'z')
            postfix += infix[i];
        else if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && priority(st.top()) >= priority(infix[i])) {
                postfix += st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

double evaluatePostfix(std::string postfix, double a, double b, double c, double d, double e)
{
    std::stack<long double> st;

    for (int i = 0; i < postfix.length(); i++) {
        if (postfix[i] == ' ')
            continue;
        if (postfix[i] >= 'a' && postfix[i] <= 'z') {
            if (postfix[i] == 'a')
                st.push(a);
            else if (postfix[i] == 'b')
                st.push(b);
            else if (postfix[i] == 'c')
                st.push(c);
            else if (postfix[i] == 'd')
                st.push(d);
            else if (postfix[i] == 'e')
                st.push(e);
        }
        else {
            double operand2 = st.top();
            st.pop();
            double operand1 = st.top();
            st.pop();
            if (postfix[i] == '+')
                st.push(operand1 + operand2);
            else if (postfix[i] == '-')
                st.push(operand1 - operand2);
            else if (postfix[i] == '*')
                st.push(operand1 * operand2);
            else if (postfix[i] == '/')
                st.push(operand1 / operand2);
        }
    }

    return st.top();
}



std::pair<long double, std::string> expression::getResult(std::string s, long double a, long double b, long double c, long double d, long double e)
{
    std::string postfix = infixToPostfix(s);
    long double result = evaluatePostfix(postfix, a, b, c, d, e);
    return std::make_pair(result, postfix);
}
