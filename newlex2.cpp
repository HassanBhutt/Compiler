#include <tuple>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <map>

using namespace std;

std::vector<std::pair<std::string, std::string>> array;
std::vector<std::tuple<std::string, std::string, std::string>> array3d;
int flag = 1;
string lexeme = "";
int state = 0;
bool is_Letter(char ch);
bool is_Digit(char ch);
bool is_Delimeter(char ch);

bool is_Letter(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_'))
        return true;
    else
        return false;
}
bool is_String(char ch)
{
    if (ch == '"')
        return true;
    else
        return false;
}

bool is_Digit(char ch)
{
    if ((ch >= '0' && ch <= '9'))
        return true;
    else
        return false;
}
bool is_Delimeter(char ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\n')
        return true;
    else
        return false;
}
bool is_SpecialCharacter(char ch)
{
    if (ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';' || ch == ',' || ch == '#' || ch == '~' || ch == '(' || ch == ')')
        return true;
    else
        return false;
}

bool is_Operators(char ch)
{
    if (ch == '+' || ch == '!' || ch == '-' || ch == '/' || ch == '*' || ch == '*' || ch == '%' || ch == '<' || ch == '>' || ch == '&' || ch == '|' || ch == '^' || ch == '=' || ch == '.')
        return true;
    else
        return false;
}

void q0(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_'))
    {
        state = 1;
    }
    else if (is_Digit(c))
    {
        state = 2;
    }
    else if (is_SpecialCharacter(c))
    {
        state = 0;
        lexeme += c;

        cout << "Token"
             << " Special Character " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Special Character"));
        lexeme = "";
        flag = 0;
    }
    else if (c == '^' || c == '!' || c == '.')
    {
        lexeme += c;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        state = 0;
        flag = 0;
    }
    else if (is_Delimeter(c))
    {

        state = 0;
        lexeme = "";
        flag = 0;
    }
    else if (c == '"')
    {
        state = 8;
    }

    else if (c == '/')
    {
        state = 4;
    }
    else if (c == '+')
    {
        state = 9;
    }
    else if (c == '-')
    {
        state = 10;
    }
    else if (c == '%' || c == '*')
    {
        state = 11;
    }

    else if (c == '>')
    {
        state = 12;
    }

    else if (c == '&')
    {
        state = 14;
    }
    else if (c == '<')
    {
        state = 15;
    }
    else if (c == '|')
    {
        state = 17;
    }
    else if (c == '=')
    {
        state = 18;
    }
    else
    {
        state = -1;
    }
}
void q1(char c)
{
    if (is_Letter(c) || (c >= '0' && c <= '9'))
    {
        state = 1;
    }
    else if (is_SpecialCharacter(c) || is_Operators(c) || is_Delimeter(c) || is_String(c))
    {

        if (lexeme == "alignas" || lexeme == "decltype" || lexeme == "namespace" || lexeme == "struct" || lexeme == "alignof" || lexeme == "default" || lexeme == "new" || lexeme == "switch" || lexeme == "and" || lexeme == "delete" || lexeme == "noexcept" || lexeme == "template" || lexeme == "and_eq" || lexeme == "do" || lexeme == "not" || lexeme == "this" || lexeme == "asm" || lexeme == "double" || lexeme == "not_eq" || lexeme == "thread_local" || lexeme == "auto" || lexeme == "dynamic_cast" || lexeme == "nullptr" || lexeme == "throw" || lexeme == "bitand" || lexeme == "else" || lexeme == "operator" || lexeme == "true" || lexeme == "bitor" || lexeme == "enum" || lexeme == "or" || lexeme == "try" || lexeme == "bool" || lexeme == "explicit" || lexeme == "or_eq" || lexeme == "typedef" || lexeme == "break" || lexeme == "export" || lexeme == "private" || lexeme == "typeid" || lexeme == "case" || lexeme == "extern" || lexeme == "protected" || lexeme == "typename" || lexeme == "catch" || lexeme == "false" || lexeme == "public" || lexeme == "union" || lexeme == "char" || lexeme == "float" || lexeme == "register" || lexeme == "unsigned" || lexeme == "char16_t" || lexeme == "for" || lexeme == "reinterpret_cast" || lexeme == "using" || lexeme == "char32_t" || lexeme == "friend" || lexeme == "return" || lexeme == "virtual" || lexeme == "class" || lexeme == "goto" || lexeme == "short" || lexeme == "void" || lexeme == "compl" || lexeme == "if" || lexeme == "signed" || lexeme == "volatile" || lexeme == "const" || lexeme == "inline" || lexeme == "sizeof" || lexeme == "wchar_t" || lexeme == "constexpr" || lexeme == "int" || lexeme == "static" || lexeme == "while " || lexeme == "const" || lexeme == "cast" || lexeme == "long" || lexeme == "static_assert" || lexeme == "xor" || lexeme == "continue" || lexeme == "mutable" || lexeme == "static_cast" || lexeme == "xor_eq")
        {
            cout << "Token"
                 << " Keyword " << lexeme << endl;

            ::array.push_back(std::make_pair(lexeme, "Token Keyword"));
        }

        else
        {
            cout << "Token"
                 << " Identifier " << lexeme << endl;
            ::array.push_back(std::make_pair(lexeme, "Token Identifier"));
            ::array3d.push_back(std::make_tuple(lexeme, "", ""));
        }
        lexeme = "";
        q0(c);
    }

    else
    {
        state = -1;
    }
}
void q2(char c)
{
    if (is_Digit(c))
    {
        state = 2;
    }
    else if (c == '.')
    {
        state = 3;
    }
    else if (is_SpecialCharacter(c) || is_Letter(c) || is_Operators(c) || is_Delimeter(c) || is_String(c))
    {
        cout << "Token"
             << " Constant " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Constant"));

        lexeme = "";
        q0(c);
    }

    else
    {
        state = -1;
    }
}

void q3(char c)
{
    if (is_Digit(c))
    {
        state = 3;
    }
    else if (is_Letter(c) || is_SpecialCharacter(c) || is_Delimeter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Constant " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Constant"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q4(char c)
{

    if (c == '/')
    {
        state = 5;
    }

    else if (c == '*')
    {
        state = 6;
    }
    else if (c == '=')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q5(char c)
{
    if (c == '\n')
    {
        state = 0;
        lexeme = "";
        flag = 0;
    }

    else
    {
        state = 5;
    }
}

void q6(char c)
{
    if (c == '*')
    {
        state = 7;
    }
    else
    {
        state = 6;
    }
}

void q7(char c)
{
    if (c == '/')
    {
        lexeme += c;
        state = 0;
        lexeme = "";
        flag = 0;
    }
    else
    {
        state = -1;
    }
}
void q8(char c)
{
    if (c == '"')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " String " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token String"));
        lexeme = "";
        flag = 0;
    }
    else
    {
        state = 8;
    }
}

void q9(char c)
{
    if (c == '+')
    {
        lexeme += c;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        state = 0;
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}
void q10(char c)
{
    if (c == '-')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (c == '>')
    {
        lexeme += c;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
        state = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q11(char c)
{
    if (c == '=')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));

        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q12(char c)
{
    if (c == '=')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (c == '>')
    {
        state = 13;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q13(char c)
{
    if (c == '>')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q14(char c)
{
    if (c == '&')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }

    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q15(char c)
{
    if (c == '<')
    {
        state = 16;
    }

    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q16(char c)
{
    if (c == '<')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q17(char c)
{
    if (c == '|')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void q18(char c)
{
    if (c == '=')
    {
        lexeme += c;
        state = 0;

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));
        lexeme = "";
        flag = 0;
    }
    else if (is_Delimeter(c) || is_Letter(c) || is_Digit(c) || is_SpecialCharacter(c) || is_Operators(c) || is_String(c))
    {

        cout << "Token"
             << " Operator " << lexeme << endl;
        ::array.push_back(std::make_pair(lexeme, "Token Operator"));

        lexeme = "";
        q0(c);
    }
    else
    {
        state = -1;
    }
}

void lexical(ifstream &fs)
{
    char c;
    while (fs >> noskipws >> c)
    {
        flag = 1;
        if (state == 0)
        {
            q0(c);
        }
        else if (state == 1)
        {
            q1(c);
        }
        else if (state == 2)
        {
            q2(c);
        }
        else if (state == 3)
        {
            q3(c);
        }
        else if (state == 4)
        {
            q4(c);
        }
        else if (state == 5)
        {
            q5(c);
        }
        else if (state == 6)
        {
            q6(c);
        }
        else if (state == 7)
        {
            q7(c);
        }
        else if (state == 8)
        {
            q8(c);
        }
        else if (state == 9)
        {
            q9(c);
        }
        else if (state == 10)
        {
            q10(c);
        }
        else if (state == 11)
        {
            q11(c);
        }
        else if (state == 12)
        {
            q12(c);
        }
        else if (state == 13)
        {
            q13(c);
        }
        else if (state == 14)
        {
            q14(c);
        }
        else if (state == 15)
        {
            q15(c);
        }
        else if (state == 16)
        {
            q16(c);
        }
        else if (state == 17)
        {
            q17(c);
        }
        else if (state == 18)
        {
            q18(c);
        }
        if (flag)
            lexeme = lexeme + c;
    }
}

int main()
{
    array3d.push_back(std::make_tuple("Name", "      Type", "      Scope"));
    ifstream fs("file.txt");
    if (fs)
    {
        lexical(fs);
        /*for (int i = 0; i < ::array.size(); i++)
         {
             cout << "Token: " << ::array[i].first << "\t\t Type: " << ::array[i].second << endl;
         }*/

        for (const auto &tuple : array3d)
        {
            cout << "" << get<0>(tuple) << " " << get<1>(tuple) << " " << get<2>(tuple) << "" << endl;
        }

        fs.close();
        }
    else
    {
        cout << "Error opening file." << endl;
    }

    return 0;
}