class Negation : public SubExpression
{
public:
    Negation(Expression* left) :
        SubExpression(left)
    {
    }
    int evaluate()
    {
        //If the value is 0 (false) then make it true (1), otherwise it must be true so make it false (0)
        if (left->evaluate() == 0) {
            return 1;
        } else {
            return 0;
        }
    }
};