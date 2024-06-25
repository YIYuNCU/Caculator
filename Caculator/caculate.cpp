#include "pch.h"
#include "caculate.h"
#include "invert.h"
#include <stdexcept>
#include <sstream>
/// <summary>
/// �������ȼ�(����������Ҫ�������ļ�ʹ�ã���δ��.h�ļ�����)
/// </summary>
/// <param name="token">��Ҫ�������ȼ����ַ�</param>
/// <returns>���ȼ�(int)</returns>
int getPriority(char token) 
{
    if (token == '+' || token == '-')
        return 1; // �ӷ��ͼ��������ȼ�Ϊ1
    else if (token == '*' || token == '/')
        return 2; // �˷��ͳ��������ȼ�Ϊ2
    else if (isdigit(token))
        return 3; // ���ֵ����ȼ�Ϊ3
    else if (token == '(')
        return 0; // �����ŵ����ȼ�Ϊ0
    else if (token == ')')
        return 4; // �����ŵ����ȼ�Ϊ4
    else
        return -1; // ��Ч����������ַ�
}

std::string infixToPostfix(const std::string& infix) 
{
    std::stack<char> opStack; // �洢����������ŵ�ջ
    std::string postfix; // �洢��׺���ʽ
    std::string operand; // ��ʱ�洢���������ַ���
    for (char c : infix) {
        if (isdigit(c) || c == '.') //�����ִ�����ʱ�洢�ַ���
        { 
            operand += c; 
        }
        else if (c == '(') //���������Ž���ѹ���ջ
        { 
            opStack.push(c); 
        }
        else if (c == ')') 
        {
            if (!operand.empty()) //��������֣����䵯�����������ʱ�洢�ַ���
            {
                postfix += operand + " ";
                operand.clear();
            }
            while (!opStack.empty() && opStack.top() != '(') //���������Ž�������������ʽ��ֱ������������
            { 
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            if (!opStack.empty() && opStack.top() == '(') //����������
            { 
                opStack.pop();
            } 
        }
        else //�����������
        { 
            if (!operand.empty()) //��������֣����䵯�����������ʱ�洢�ַ���
            { 
                postfix += operand + " "; 
                operand.clear(); 
            }
            while (!opStack.empty() && opStack.top() != '(' && getPriority(opStack.top()) >= getPriority(c)) // ����ջ�����ȼ����ڻ���ڵ�ǰ������������
            { 
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(c); // ����ǰ�����ѹ��ջ
        }
    }
    if (!operand.empty()) // ��ʣ��Ĳ�������ӵ���׺���ʽ��
    { 
        postfix += operand; 
    }
    while (!opStack.empty()) // ��ջ��ʣ����������ӵ���׺���ʽ��
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
    std::stack<double> valueStack;//��ֵ��ջ
    std::string operand;//��ʱ�洢��ֵ���ַ���
    for (char c : postfix) //������������ʽ
    {
        if (isdigit(c) || c == '.')  ///������ʽ�е�����ȡ����
        {
            operand += c;
        }
        else if (c == ' ') //��ȡ��һ��������ѹ���ջ
        {
            if (!operand.empty()) 
            {
                valueStack.push(stringToDouble(operand));
                operand.clear();//���֮ǰ�洢����
            }
        }
        else 
        {
            //����ջ��������
            double b = valueStack.top();
            valueStack.pop();
            double a = valueStack.top();
            valueStack.pop();
            //���ݼ�������㣬�����������ѹ���ջ
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
        // ���ʽΪ�ջ���Ч
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
/// ��һ���������ֵ��ַ�������ȡ����
/// </summary>
/// <param name="origin">��ʼ�ַ���(std::string)</param>
/// <returns>��ȡ��������(std::string)</returns>
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
    std::string operand;//��ʱ�洢��ֵ���ַ���
    std::string temp;//��ʱ��ű��ʽ���ַ���
    char lastop = ' ';
    if (origin.at(0) == '-')
    {
        operand += "(0-";
        lastop = '!';
    }
    for (const char c : origin)
    {
        if (isdigit(c) || c == '.')  ///������ʽ�е�����ȡ����
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

