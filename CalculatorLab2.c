#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100

// Function prototypes to be able to be called before the methods or functions are fully created
double evaluateExpression(const char *expr);
double parseTerm(const char **expr);
double parseFactor(const char **expr);
double parseNumber(const char **expr);

int main() 
{
   char expression[MAX_EXPR_LEN];

    printf("Enter an expression: ");
    fgets(expression, MAX_EXPR_LEN, stdin);

    double result = evaluateExpression(expression);
    printf("Result: %lf\n", result);

    return 0;
}

//this method looks for addition and subtraction in the expression at the current operator
double evaluateExpression(const char *expr) 
{
   double result = parseTerm(&expr);
    //this while loop calls checks for addition and subtraction and then calls parseTerm
    while (*expr) {
        if (*expr == '+') {
            expr++;
            result += parseTerm(&expr);
        } else if (*expr == '-') {
            expr++;
            result -= parseTerm(&expr);
        } else {
            break;
        }
    }

    return result;
}
//this method is for multiplication and division
double parseTerm(const char **expr) 
{
    return 0;
}

//this method checks for the operators sin, cos, tan, ln, and log10 along with parenthesis
double parseFactor(const char **expr) 
{
    return 0;
}

//checks if the the current number is a negative and if the number is a decimal
double parseNumber(const char **expr) 
{
   return 0;
}
