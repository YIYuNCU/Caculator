#pragma once

/// <summary>
/// ��׺�ĺ�׺
/// </summary>
/// <param name="infix">��׺��ʽ(std::string)</param>
/// <returns>��׺��ʽ(std::string)</returns>
std::string infixToPostfix(const std::string& infix);
/// <summary>
/// �����׺ֵ
/// </summary>
/// <param name="postfix">��׺����ʽ(std::string)</param>
/// <returns>������(double)</returns>
double evaluatePostfix(const std::string& postfix);
/// <summary>
/// ��ֵ�Ϸ���
/// </summary>
/// <param name="origin">��ʼ�ַ�</param>
/// <returns>������ַ�(std::string)</returns>
std::string legitimize(std::string& origin);
/// <summary>
/// �жϼ���ʽ�Ƿ�Ϸ�
/// </summary>
/// <param name="origin">����ʽ(std::string)</param>
/// <returns>�Ƿ�Ϸ�</returns>
bool isLegally(std::string& origin);
/// <summary>
/// �ж��ַ����Ƿ��ʾ����
/// </summary>
/// <param name="origin">��Ҫ�жϵ��ַ���</param>
/// <returns>�Ƿ�Ϊ����</returns>
bool isNum(std::string& origin);