#include <cstring>
using namespace std;

class Person{
    private:
        double weight;
        double height;
        char * name;
    
    public:
        Person();

        Person(double weight, double height, char name[]);

        void setWeight(double weight);

        double getWeight();

        void setHeight(double height);

        double getHeight();

        void setName(char name[]);

        char* getName();

        double getRatio();

};