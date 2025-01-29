/*
Honor Code: "I pledge that I have neither given nor received help from anyone other than the
instructor/TA for all program components included here!"
Name: Xavier Santiago
CWU ID: 41895341
Lab 2
*/
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
    
    //checks if there is addition
        if (*expr == '+') {
            expr++;
            result += parseTerm(&expr);
        }
         
    //else checks if there is subtraction and then subtracts from parseTerm
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
    //checks for multiplication then multiplies result to parseFactor method return
        if (**expr == '*') {
            (*expr)++;
            result *= parseFactor(expr);
        }
    //else checks for division and divides result with parseFactor 
        else if (**expr == '/') {
            (*expr)++;
            result /= parseFactor(expr);
        }
    //checks for exponent then solve for it  
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
double parseFactor(const char **expr) {
    double result;
    //if the expression has parenthesis then do that first and do the math inside of it then move on
    if(**expr == '-' && *(*expr + 1) == '('){
        (*expr) += 2;
        result = -1 * evaluateExpression(*expr);
    }
    
    else if (**expr == '(') {
        (*expr)++;
        result = evaluateExpression(*expr);
        while (**expr && **expr != ')'){
            (*expr)++;
        }
        
        if (**expr == ')') {
            (*expr)++;
        }
    } 
    
    //this else if checks for sin() and solves based on the number in parenthesis
    else if (**expr == 's' && *(*expr + 1) == 'i' && *(*expr + 2) == 'n') {
        *expr += 3;
        if (**expr == '(') {
            (*expr)++;
            result = sin(evaluateExpression(*expr)* (M_PI / 180.0));
            while (**expr && **expr != ')') {
                (*expr)++;
            }
            if (**expr == ')') {
                (*expr)++;
            }
        }
    } 
    
    //checks for tan() and solves based on the number in parenthesis
    else if (**expr == 't' && *(*expr + 1) == 'a' && *(*expr + 2) == 'n') {
        *expr += 3;
        if (**expr == '(') {
            (*expr)++;
            result = tan(evaluateExpression(*expr)* (M_PI / 180.0));
            while (**expr && **expr != ')') {
                (*expr)++;
            }
            
            if (**expr == ')') {
                (*expr)++;
            }
        }
    }
    
    //checks for cos() and solves based on the number in parenthesis
    else if (**expr == 'c' && *(*expr + 1) == 'o' && *(*expr + 2) == 's') {
        *expr += 3;
        if (**expr == '(') {
            (*expr)++;
            result = cos(evaluateExpression(*expr)* (M_PI / 180.0));
            while (**expr && **expr != ')') {
                (*expr)++;
            }
            
            if (**expr == ')') {
                (*expr)++;
            }
        }
    }
    
    //checks for ln() and solves based on the number in parenthesis
    else if (**expr == 'l' && *(*expr + 1) == 'n') {
        *expr += 2;
        if (**expr == '(') {
            (*expr)++;
            result = log(evaluateExpression(*expr));
            while (**expr && **expr != ')') {
                (*expr)++;
            }
            
            if (**expr == ')') {
                (*expr)++;
            }
        }
    }
    
    //checks for log10 and solves based on the number in parenthesis
    else if (**expr == 'l' && *(*expr + 1) == 'o' && *(*expr + 2) == 'g' && *(*expr + 3) == '1' && *(*expr + 4) == '0') {
        *expr += 5;
        if (**expr == '(') {
            (*expr)++;
            result = log10(evaluateExpression(*expr));
            while (**expr && **expr != ')') {
                (*expr)++;
            }
            if (**expr == ')') {
                (*expr)++;
            }
        }
    }
    //calls the method parseNumber
    else {
        result = parseNumber(expr);
    }

    return result;
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
