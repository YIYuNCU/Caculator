#pragma once

/// <summary>
/// CString����תstd::string����
/// </summary>
/// <param name="cstr">��Ҫת����CString�ַ���</param>
/// <returns>ת�����std::string�����ַ���</returns>
std::string CStringToStdString(const CString& cstr);

/// <summary>
/// string����תdouble����
/// </summary>
/// <param name="str">��Ҫת����std::string�ַ���</param>
/// <param name="endptr">�ַ�����βָ��</param>
/// <returns>ת�����double������</returns>
double stringToDouble(const std::string& str, char** endptr = nullptr);

/// <summary>
/// double����תCString����
/// </summary>
/// <param name="value">��Ҫת������</param>
/// <param name="precision">ת������(����С��λ��)</param>
/// <returns>ת�����CString�����ַ���</returns>
CString DoubleToString(double value, int precision = 6);

/// <summary>
/// double����תstd::string����
/// </summary>
///  <param name="value">��Ҫת������</param>
///  <param name="precision">ת������(����С��λ��)</param>
///  <returns>ת�����std::string�����ַ���</returns>
std::string DoubleToStdString(double value, int precision);

