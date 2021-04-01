class Lesser : public SubExpression
{
public:
    Lesser(Expression* left, Expression* right) :
        SubExpression(left, right)
    {
    }
    int evaluate()
    {
        return left->evaluate() < right->evaluate();
    }
};