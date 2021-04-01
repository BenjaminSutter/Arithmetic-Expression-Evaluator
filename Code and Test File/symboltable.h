class SymbolTable
{
public:
    SymbolTable() {}
    void insert(string variable, double value);
    double lookUp(string variable) const;

    //Clears the values in the expression so different values can be produced, found from William Crutchfield (line 7):
    //https://github.com/CrutchTheClutch/CMSC-330-Project-2/blob/master/Project-2/symboltable.h#L7
    void init() {elements.clear();}
private:
    struct Symbol
    {
        Symbol(string variable, double value)
        {
            this->variable = variable;
            this->value = value;
        }
        string variable;
        double value;
    };
    vector <Symbol> elements;
};