#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

string helpStr = "Greeble is a birds-eye view C++ project manager.";

void parseToken(string token)
{
    //Construct abstract syntax tree
}

int main()
{
    fstream config(".greeble");
    if(config.good())
    {
        cout << "Running Greeble" << endl;

        string token;
        config >> ws; //Extract additional whitespace
        while(getline(config, token))
        {
            stringstream ss(token);

            parseToken(token);

            config >> ws;
        }
    }
    else
    {
        //Greeble not found, print help
        cout << ".greeble not found" << endl << endl;
        cout << helpStr << endl;
    }

    config.close();

    return 0;
}