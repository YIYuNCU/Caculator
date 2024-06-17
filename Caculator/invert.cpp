#include "pch.h"
#include "invert.h"

std::string CStringToStdString(const CString& cstr)
{
    CT2CA astr(cstr);//��CStringת��ΪANSI�ַ���
    std::string strStd(astr);//��ANSI�ַ���ת��Ϊstd::string
    return strStd;
}

double stringToDouble(const std::string& str, char** endptr)
{
    return std::strtod(str.c_str(), endptr);
}

CString DoubleToString(double value, int precision)
{
    CString str;
    str.Format(_T("%.*g"), precision, value);
    return str;
}

std::string DoubleToStdString(double value, int precision)
{
    CString str;
    str.Format(_T("%.*g"), precision, value);
    std::string temp = CStringToStdString(str);
    return temp;
}

CString StdStringToString(const std::string sstr)
{
    CString temp;
    temp = sstr.c_str();
    return temp ;
}