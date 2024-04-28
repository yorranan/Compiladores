#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}
bool isBracket(char ch)
{
    return (ch == '(' || ch == ')');
}
bool isArithmeticOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
bool isLogicalOperator(char ch)
{
    return (ch == '>' || ch == '<' || ch == '=' || ch == '!');
}
bool isInteger(char *str)
{
    if (str == NULL || *str == '\0')
    {
        return false;
    }

    int i = 0;
    while (isDigit(str[i]))
    {
        i++;
    }
    return str[i] == '\0';
}
bool isFloat(char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }

    int i = 0;
    int dotCount = 0;

    while (str[i] != '\0') {
        if (isDigit(str[i])) {
            i++;
        } else if (str[i] == '.') {
            dotCount++;
            i++;
        } else {
            return false;
        }
    }

    return dotCount == 1;
}
char *getSubstring(char *str, int start, int end)
{
    int length = strlen(str);
    int subLength = end - start + 1;
    char *subStr = (char *)malloc((subLength + 1) * sizeof(char));
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}
int lexicalAnalyzer(char *input)
{
    int left = 0, right = 0;
    int len = strlen(input);

    while (right <= len && left <= right)
    {
        while (input[right] != ' ' && !isLogicalOperator(input[right]) && !isArithmeticOperator(input[right]) && !isBracket(input[right]) && right < len)
        {
            right++;
        }
        char *str = getSubstring(input, left, right - 1);
        if (isInteger(str))
        {
            printf("<Inteiro, %s>\n", str);
        }
        else if (isFloat(str))
        {
            printf("<Real, %s>\n", str);
        }
        
        if (isArithmeticOperator(input[right]))
        {
            printf("<Operador Aritmético, %c>\n", input[right]);
        }
        else if (isLogicalOperator(input[right]))
        {
            printf("<Operador Lógico, %c>\n", input[right]);
        }
        else if (isBracket(input[right]))
        {
            printf("<Parêntese, %c>\n", input[right]);
        }
        else if (input[right] == ' ' || input[right] == '\0')
        {
            // faça nada
        }
        else
        {
            printf("<Não reconhecido, %s>\n", str);
        }
        left = right+1;
        right++;
    }
    return 0;
}