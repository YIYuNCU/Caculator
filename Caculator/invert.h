#pragma once

/// <summary>
/// CString类型转std::string类型
/// </summary>
/// <param name="cstr">需要转换的CString字符串</param>
/// <returns>转换后的std::string类型字符串</returns>
std::string CStringToStdString(const CString& cstr);

/// <summary>
/// string类型转double类型
/// </summary>
/// <param name="str">需要转换的std::string字符串</param>
/// <param name="endptr">字符串结尾指针</param>
/// <returns>转换后的double类型数</returns>
double stringToDouble(const std::string& str, char** endptr = nullptr);

/// <summary>
/// double类型转CString类型
/// </summary>
/// <param name="value">需要转换的数</param>
/// <param name="precision">转换精度(保留小数位数)</param>
/// <returns>转换后的CString类型字符串</returns>
CString DoubleToString(double value, int precision = 6);

/// <summary>
/// double类型转std::string类型
/// </summary>
///  <param name="value">需要转换的数</param>
///  <param name="precision">转换精度(保留小数位数)</param>
///  <returns>转换后的std::string类型字符串</returns>
std::string DoubleToStdString(double value, int precision);

