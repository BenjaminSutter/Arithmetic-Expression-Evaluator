//Test
#include <cctype> 
#include <iostream> 
#include <string> 
#include <sstream> 
using namespace std;

#include "parse.h"

string parseName(stringstream& ss)
{
    char alnum;
    string name = "";

    ss >> ws;
    while (isalnum(ss.peek()))
    {
        ss >> alnum;
        name += alnum;
    }
    return name;
}