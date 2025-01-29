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
        } 
        else if (*expr == '-') {
            expr++;
            result -= parseTerm(&expr);
        } 
        else {
            break;
        }
    }

    return result;
}
//this method is for multiplication and division and exponent
double parseTerm(const char **expr) {
    double result = parseFactor(expr);
    //this while method multiplies and divides, also checks for exponent then it calls the parseFactor method to check for parenthesis
    while (**expr) {
        if (**expr == '*') {
            (*expr)++;
            result *= parseFactor(expr);
        } 
        else if (**expr == '/') {
            (*expr)++;
            result /= parseFactor(expr);
        } 
        else if (**expr == '^') {
            (*expr)++;
            result = pow(result,parseFactor(expr));
        } 
        else {
            break;
        }
    }

    return result;
}

//this method checks for the operators sin, cos, tan, ln, and log10 along with parenthesis
double parseFactor(const char **expr) 
{
    return 0;
}

//checks if the the current number is a negative and if the number is a decimal
double parseNumber(const char **expr) {
    double result = 0.0;
    int sign = 1;

    if (**expr == '-') {
        sign = -1;
        (*expr)++;
    }
    //checks if the current character is either a number or a period which means decimal
    while (isdigit(**expr) || **expr == '.') {
    //if the current character hass a period then make the number a decimal or double
        if (**expr == '.') {
            (*expr)++;
            double fraction = 1.0;
            while (isdigit(**expr)) {
                fraction /= 10.0;
                result += (**expr - '0') * fraction;
                (*expr)++;
            }
        } 
        else {
            result = result * 10.0 + (**expr - '0');
            (*expr)++;
        }
    }

    return sign * result;
}
