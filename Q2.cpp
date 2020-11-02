#include "Person.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int N;
    double height, weight, smallestRatio;
    char name[40];
    cin >> N;
    Person people[N];
    Person sortedPeople[N];

    for (int i = 0; i < N; i++)
    {
        cin >> weight;
        cin >> height;
        cin.getline(name, 40, '\n');
        for (int j = 0; j < strlen(name); j++)
        {
            name[j] = name[j+1];
        }

        people[i].setWeight(weight);
        people[i].setHeight(height);
        people[i].setName(name);
    }

    int max;
    Person temp;
    for (int i = 0; i < N; i++)
    {
        max = i;
        for (int j = i + 1; j < N; j++)
        {
            if (people[j].getRatio() > people[max].getRatio())
                max = j;
        }
            temp = people[i];
            people[i] = people[max];
            people[max] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        cout << people[i].getName() << " " << people[i].getRatio() << endl; 
    }

    return 0;
}