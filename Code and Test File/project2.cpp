#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& ss);

int main()
{
    Expression* expression;
    char paren, comma;

    //Method  to read file retrieved from slide 9 of:
    http://ee.usc.edu/~redekopp/cs103/slides/Unit14_Streams.pdf
    int line_no = 0;
    ifstream myfile("Input.txt");
    string myline;
    while (getline(myfile, myline)) {
        symbolTable.init(); //Clears the values in the expression so different values from lines can be produced, found from William Crutchfield (line 25):
        //https://github.com/CrutchTheClutch/CMSC-330-Project-2/blob/master/Project-2/module3.cpp
        
        stringstream ss; //Initializes stringstream that will be passed to other methods (replicates cin in a way)
        ss << myline;//Creates the stream based off of the current line
        ss >> paren;
        expression = SubExpression::parse(ss);
        ss >> comma;
        parseAssignments(ss);
        int result = expression->evaluate();
        cout << myline << "   Value = " << result << endl;

    }
    cout << "\nCalculations complete! \n";
    return 0;

}

void parseAssignments(stringstream& ss)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(ss);
        ss >> ws >> assignop >> value >> delimiter;
        symbolTable.insert(variable, value);
    } while (delimiter == ',');
}