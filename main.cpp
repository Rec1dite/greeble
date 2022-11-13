#include <fstream>
#include <sstream>
#include <iostream>
#include "src/interpreter/expression.h"
#include "src/interpreter/terminalExpr.h"
#include "src/interpreter/nonTerminalExpr.h"

using namespace std;

const string ansi_reset     = "\033[0m";
const string ansi_red       = "\033[1;31m";
const string ansi_green     = "\033[1;32m";
const string ansi_yellow    = "\033[1;33m";
const string ansi_blue      = "\033[1;34m";
const string ansi_magenta   = "\033[1;35m";
const string ansi_cyan      = "\033[1;36m";
const string ansi_white     = "\033[1;37m";

const string helpMsg = "Greeble is a birds-eye view C++ project manager.";

const string splitChars = "\n ()[]{},;.!@$%^&*-_+=";

int main()
{
    fstream config("./.greeble");

    if(config.good()) //Config exists
    {
        cout << ansi_blue << "Running Greeble" << ansi_reset << endl;

        string line;
        int lineNo = 1;

        expression* syntaxRoot;

        stringstream tokenized;

        while(getline(config, line)) //Split by line
        {
            cout << "LINE " << lineNo << endl;

            stringstream ss(line);
            string token;

            while(ss >> token) //Split by whitespace
            {
                //Split by character differences
                stringstream ss2(token);
                string split;

                for(auto c : splitChars)
                {
                    getline(ss2, split, c);
                }

                if(token.length() > 0)
                {
                    if(token[0] == '#') //Comment, ignore rest of line
                    {
                        break; //Jump to next line
                    }
                    else
                    {
                        //Pass token to syntax tree parser
                        cout << '\t' << ansi_red << split << ansi_reset << endl;
                    }
                }
            }
            lineNo++;
        }
    }
    else
    {
        //Greeble not found, print help
        cout << ".greeble not found" << endl << endl;
        cout << helpMsg << endl;
    }

    config.close();

    return 0;
}