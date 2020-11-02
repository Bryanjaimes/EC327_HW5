#include <string>
#include <iostream>
#include <fstream>
using namespace std;

void findExpression(int N, string & expr)
{
    string words[N], temp;
    int i;
    bool contains = 0;
    ifstream file;
    ofstream myoutput;

    file.open("words.txt");
    if(file.fail())
        cout<<"No such file\n";
    else
    {
        int i = 0;
        while(!file.eof() && i < N)
        {
            file>>words[i];
            i++;
        }
    }
    file.close();

    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        if (words[i].find(expr) != std::string::npos)
            counter++;
    }

    string output[counter];

    int size = counter;
    counter = 0;
    for (int i = 0; i < N; i++)
    {
        if (words[i].find(expr) != std::string::npos)
        {
            output[counter] = words[i];
            counter++;
        }   
    }

    myoutput.open("output.txt");
    for (int i = 0; i < size; i++)
        myoutput << output[i] << endl;;

    myoutput.close();

}
