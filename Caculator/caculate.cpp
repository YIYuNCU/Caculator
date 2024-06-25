#include "pch.h"
#include "caculate.h"
#include "invert.h"
#include <stdexcept>
#include <sstream>
/// <summary>
/// 计算优先级(本函数不需要在其他文件使用，故未在.h文件声明)
/// </summary>
/// <param name="token">需要计算优先级的字符</param>
/// <returns>优先级(int)</returns>
int getPriority(char token) 
{
    if (token == '+' || token == '-')
        return 1; // 加法和减法的优先级为1
    else if (token == '*' || token == '/')
        return 2; // 乘法和除法的优先级为2
    else if (isdigit(token))
        return 3; // 数字的优先级为3
    else if (token == '(')
        return 0; // 左括号的优先级为0
    else if (token == ')')
        return 4; // 右括号的优先级为4
    else
        return -1; // 无效的运算符或字符
}

std::string infixToPostfix(const std::string& infix) 
{
    std::stack<char> opStack; // 存储运算符和括号的栈
    std::string postfix; // 存储后缀表达式
    std::string operand; // 临时存储操作数的字符串
    for (char c : infix) {
        if (isdigit(c) || c == '.') //将数字存入临时存储字符串
        { 
            operand += c; 
        }
        else if (c == '(') //遇到左括号将其压入堆栈
        { 
            opStack.push(c); 
        }
        else if (c == ')') 
        {
            if (!operand.empty()) //如果有数字，则将其弹出，并清空临时存储字符串
            {
                postfix += operand + " ";
                operand.clear();
            }
            while (!opStack.empty() && opStack.top() != '(') //遇到右括号将运算符弹出表达式，直到遇到左括号
            { 
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') //弹出左括号
            { 
                opStack.pop();
            } 
        }
        else //遇到运算符号
        { 
            if (!operand.empty()) //如果有数字，则将其弹出，并清空临时存储字符串
            { 
                postfix += operand + " "; 
                operand.clear(); 
            }
            while (!opStack.empty() && opStack.top() != '(' && getPriority(opStack.top()) >= getPriority(c)) // 弹出栈中优先级高于或等于当前运算符的运算符
            { 
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(c); // 将当前运算符压入栈
        }
    }
    if (!operand.empty()) // 将剩余的操作数添加到后缀表达式中
    { 
        postfix += operand; 
    }
    while (!opStack.empty()) // 将栈中剩余的运算符添加到后缀表达式中
    { 
        postfix += " ";
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }
    return postfix;
}

double evaluatePostfix(const std::string& postfix) 
{
    std::stack<double> valueStack;//数值堆栈
    std::string operand;//临时存储数值的字符串
    for (char c : postfix) //遍历整个计算式
    {
        if (isdigit(c) || c == '.')  ///将计算式中的数提取出来
        {
            operand += c;
        }
        else if (c == ' ') //提取完一个数将其压入堆栈
        {
            if (!operand.empty()) 
            {
                valueStack.push(stringToDouble(operand));
                operand.clear();//清空之前存储的数
            }
        }
        else 
        {
            //弹出栈顶两个数
            double b = valueStack.top();
            valueStack.pop();
            double a = valueStack.top();
            valueStack.pop();
            //根据计算符计算，并将结果重新压入堆栈
            switch (c)
            {
            case '+':
                valueStack.push(a + b);
                break;
            case '-':
                valueStack.push(a - b);
                break;
            case '*':
                valueStack.push(a * b);
                break;
            case '/':
                valueStack.push(a / b);
                break;
            }
        }
    }
    if (valueStack.empty()) {
        // 表达式为空或无效
        throw std::runtime_error("Invalid expression");
    }
    else
    {
        double result = valueStack.top();
        return result;
    }
}

bool isNum(std::string& origin)
{
    if (origin.size() == 0)
    {
        return false;
    }
    for (const char c : origin)
    {
        if (!isdigit(c) && c != '.')
        {
            return false;
        }
    }
    return true;
}
/// <summary>
/// 从一个包含数字的字符串中提取数字
/// </summary>
/// <param name="origin">初始字符串(std::string)</param>
/// <returns>提取到的数字(std::string)</returns>
std::string getNum(std::string origin)
{
    std::string temp;
    for (const char c : origin)
    {
        if (isdigit(c) || c == '.')
        {
            temp += c;
        }
    }
    return temp;
}
bool isLegally(std::string& origin)
{
    char lastop = ' ';
    int brackets = 0;
    for (const char c : origin)
    {
        if (c == -68)
        {
            return false;
        }
        if (isdigit(c))
        {
            if (lastop == 'p')
            {
                return false;
            }
            lastop = 'n';
        }
        else if (c == '+' || c == '*' || c == '/'|| c == '-')
        {
            if (lastop == 'o')
            {
                return false;
            }     
            lastop = 'o';
        }
        else if (c == '%')
        {
            if (lastop == 'o'||lastop =='p')
            {
                return false;
            }
            lastop = 'p';
        }
        if (c == '(')
        {
            brackets += 1;
            lastop = 'b';
        }
        else if (c == ')')
        {
            brackets -= 1;
            lastop = 'b';
        }
    }
    if (brackets != 0)
    {
        return false;
    }
    if (!isdigit(origin.at(origin.size()-1)) && origin.at(origin.size() - 1) != ')' && origin.at(origin.size() - 1) != '%')
    {
        return false;
    }
    return true;
}
std::string legitimize(std::string& origin)
{
    std::string operand;//临时存储数值的字符串
    std::string temp;//临时存放表达式的字符串
    char lastop = ' ';
    if (origin.at(0) == '-')
    {
        operand += "(0-";
        lastop = '!';
    }
    for (const char c : origin)
    {
        if (isdigit(c) || c == '.')  ///将计算式中的数提取出来
        {
            operand += c;
            if (lastop != 'f')
            {
                lastop = c;
            }
        }
        else if (c == '+' || c == '*' || c == '/')
        {
            if (!isNum(operand) && lastop != '%')
            {
                operand += ')';
            }
            temp += operand + c;
            operand.clear();
            lastop = c;
        }
        else if (c == '-')
        {
            if (lastop == '*' || lastop == '/' || lastop == '+' || lastop == '-'|| lastop == '(')
            {
                operand += "(0-";
                lastop = 'f';
            }
            else if(lastop != '!')
            {
                if (!isNum(operand) && lastop != '%')
                {
                    operand += ')';
                }
                temp += operand + c;
                operand.clear();
                lastop = c;
            }
        }
        else if (c == '%')
        {
            double pertemp;
            if (isNum(operand))
            {
                pertemp = stringToDouble(operand);
                pertemp = 0.01 * pertemp;
                operand = DoubleToStdString(pertemp, 10);
            }
            else if (operand.size() == 0)
            {
                operand = "*0.01";
            }
            else
            {
                std::string mtemp = getNum(operand);
                pertemp = stringToDouble(mtemp);
                pertemp = 0.01 * pertemp;
                operand = "(0-" + DoubleToStdString(pertemp, 10) + ')';
            }
            lastop = '%';
        }
        else if (c == '(' || c == ')')
        {
            if ((!isNum(operand) && operand.size() != 0) && lastop != '%')
            {
                operand += ')';
            }
            temp += operand + c;
            operand.clear();
            lastop = c;
        }
    }
    temp += operand;
    if (lastop == 'f')
    {
        temp += ')';
    }
    return temp;
}

