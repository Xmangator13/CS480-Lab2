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

}

//this method looks for addition and subtraction in the expression at the current operator
double evaluateExpression(const char *expr) 
{
   return 0;
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
