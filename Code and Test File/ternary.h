class Ternary : public SubExpression
{
public:
    Ternary(Expression* left, Expression* right, Expression* condition) :
        SubExpression(left, right, condition)
    {
    }
    int evaluate()
    {
        //If the condition is true (1) then return left, if it is not true it must be false so return right instead
        if (condition->evaluate() == 1) {
            return left->evaluate();
        } else {
            return right->evaluate();
        }
    }
};