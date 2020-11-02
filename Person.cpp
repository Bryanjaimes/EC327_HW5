#include "Person.h"
#include <cstring>
#include <iostream>
using namespace std;

Person::Person()
{

}

Person::Person(double weight, double height, char name[])
{
    this->weight = weight;
    this->height = height;

    int size = strlen(name) + 1;
    this -> name = new char[size + 1];
    strncpy(this->name, name, size);
    this-> name[size - 1] = '\0';

}

void Person::setWeight(double weight)
{
    this->weight = weight;
}

double Person::getWeight()
{
    return this->weight;
}

void Person::setHeight(double height)
{
    this->height = height;
}

double Person::getHeight()
{
    return this->height;
}

void Person::setName(char name[])
{
    int size = strlen(name) + 1;
    this -> name = new char[size + 1];
    strncpy(this->name, name, size);
    this-> name[size - 1] = '\0';
}

char* Person::getName()
{
    return this->name;
}

double Person::getRatio()
{
    return (this->height)/(this->weight);
}