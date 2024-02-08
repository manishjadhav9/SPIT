#include<stdio.h>
#include<stdlib.h>
#include <math.h>


int perform_operation(int opnd1, int opnd2, char op){
    int res;
    switch (op) {
        case '+':
            res = opnd1 + opnd2;
            break;
        case '-':
            res = opnd1 - opnd2;
            break;
        case '/':
            res = opnd1 / opnd2;
            break;
        case '*':
            res = opnd1 * opnd2;
            break;
        case '^':
            res = pow(opnd1, opnd2);
            break;
        default:
            printf("invalid operation!");
    }
    return res;
}

int get_precedence(op){
    switch (op) {
        case '+':
        case '-':
            return 3;
        case '*':
        case '/':
            return 2;
        case '^':
            return 1;
        default:
            return 4;
    }
}

int is_higher_or_equal(char op1, char op2){
    int precedence_1 = get_precedence(op1);
    int precedence_2 = get_precedence(op2);
    return precedence_1 <= precedence_2;
}

int is_higher(char op1, char op2){
    int precedence_1 = get_precedence(op1);
    int precedence_2 = get_precedence(op2);
    return precedence_1 < precedence_2;
}

int is_operator(char ch){
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '%':
            return 1;
        default:
            return 0;
        
    }
}

