#include <string>
using namespace std;

class FunString{
    public:
        int size;
        char * chars;

        FunString(char chars[], int size);

        FunString append(int n, char ch);

        FunString assign(FunString s, int n);

        int compare(FunString s) const;

        int compare(int index, int n, FunString s) const;

        char* data() const;

        bool isAnagram(const FunString &s) const;

        FunString commonSuffix(const FunString &s) const;
};