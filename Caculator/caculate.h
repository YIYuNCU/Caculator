#pragma once

/// <summary>
/// 中缀改后缀
/// </summary>
/// <param name="infix">中缀算式(std::string)</param>
/// <returns>后缀算式(std::string)</returns>
std::string infixToPostfix(const std::string& infix);
/// <summary>
/// 计算后缀值
/// </summary>
/// <param name="postfix">后缀计算式(std::string)</param>
/// <returns>计算结果(double)</returns>
double evaluatePostfix(const std::string& postfix);
/// <summary>
/// 数值合法化
/// </summary>
/// <param name="origin">初始字符</param>
/// <returns>处理后字符(std::string)</returns>
std::string legitimize(std::string& origin);
/// <summary>
/// 判断计算式是否合法
/// </summary>
/// <param name="origin">计算式(std::string)</param>
/// <returns>是否合法</returns>
bool isLegally(std::string& origin);
/// <summary>
/// 判断字符串是否表示数字
/// </summary>
/// <param name="origin">需要判断的字符串</param>
/// <returns>是否为数字</returns>
bool isNum(std::string& origin);