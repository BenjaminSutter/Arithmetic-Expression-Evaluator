class SubExpression : public Expression
{
public:
    SubExpression(Expression* left, Expression* right);
    SubExpression(Expression* left, Expression* right, Expression* condition);
    SubExpression(Expression* left);
    static Expression* parse(stringstream& ss);
protected:
    Expression* left;
    Expression* right;
    Expression* condition;
};