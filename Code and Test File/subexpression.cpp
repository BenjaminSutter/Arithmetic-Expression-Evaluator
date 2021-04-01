#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "greater.h"
#include "lesser.h"
#include "equal.h"
#include "and.h"
#include "or.h"
#include "negation.h"
#include "ternary.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
    this->left = left;
    this->right = right;
}

//For use in negation since only one parameter is needed
SubExpression::SubExpression(Expression* left)
{
    this->left = left;
}

//For use in ternery since an extra parameter is needed
SubExpression::SubExpression(Expression* left, Expression* right, Expression *condition)
{
    this->left = left;
    this->right = right;
    this->condition= condition;
}

Expression* SubExpression::parse(stringstream& ss)
{
    Expression* left;
    Expression* right;
    Expression* condition;
    char operation, paren, questionmark;

    left = Operand::parse(ss);
    ss >> operation;
    if (operation == ':') {
        right = Operand::parse(ss);
        ss >> questionmark;
        condition = Operand::parse(ss);
        ss >> paren;
        return new Ternary(left, right, condition);
    } else if (operation == '!') {
        ss >> paren;
        return new Negation(left);
    } else {
        right = Operand::parse(ss);
        ss >> paren;

        switch (operation)
        {
        case '+':
            return new Plus(left, right);
        case '-':
            return new Minus(left, right);
        case '*':
            return new Times(left, right);
        case '/':
            return new Divide(left, right);
        case '>':
            return new Greater(left, right);
        case '<':
            return new Lesser(left, right);
        case '=':
            return new Equal(left, right);
        case '&':
            return new And(left, right);
        case '|':
            return new Or(left, right);
        }
    }

    return 0;
}