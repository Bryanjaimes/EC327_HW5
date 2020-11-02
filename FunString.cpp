#include "FunString.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

FunString::FunString(char chars[], int size)
{
    this -> size = size;
    int len = strlen(chars) + 1;
    this -> chars = new char[len + 1];
    strncpy(this->chars, chars, len);
    this-> chars[len - 1] = '\0';
}

FunString FunString::append(int n, char ch)
{
    int oldsize = this -> size;
    this -> size = this -> size + n;

    for (int i = oldsize; i < this-> size; i++)
    {
        this-> chars[i] = ch;  
    }

    return *this;
}

FunString FunString::assign(FunString s, int n)
{
    for (int i = 0; i < n; i++)
    {
        this-> chars[i] = s.chars[i];
    }

    return *this;
}

int FunString::compare(FunString s) const
{
    for (int i = 0; i < this-> size && i < s.size; i++)
    {
        if (this->chars[i] > s.chars[i])
            return 1;
        else if (this->chars[i] < s.chars[i])
            return -1;
    }
    
    return 0;
}

int FunString::compare(int index, int n, FunString s) const
{
    for (int i = 0, j = index; i < this-> size && j < index + n ; i++, j++)
    {
        cout << this->chars[i] << " " << s.chars[j] << endl;
        if (this->chars[i] > s.chars[j])
            return 1;
        else if (this->chars[i] < s.chars[j])
            return -1;
    }
    
    return 0;
}

char* FunString::data() const
{
    int len = strlen(this -> chars) + 1;
    char* str = new char[len + 1];
    strncpy(str, this->chars, len);
    str[len - 1] = '\0';

    return str;
}

bool FunString::isAnagram(const FunString &s) const
{
    if (this->size != s.size)
        return false;
    else
    {
        string t1 = this->chars;
        string t2 = s.chars;

        int min;
        char temp;
        for (int i = 0; i < this->size; i++)
        {
            min = i;
            for (int j = i + 1; j < this->size; j++)
            {
                if (t1[j] > t1[min])
                    min = j;
            }
                temp = t1[i];
                t1[i] = t1[min];
                t1[min] = temp;
        }

        for (int i = 0; i < s.size; i++)
        {
            min = i;
            for (int j = i + 1; j < this->size; j++)
            {
                if (t2[j] > t2[min])
                    min = j;
            }
                temp = t2[i];
                t2[i] = t2[min];
                t2[min] = temp;
        }

        for (int i = 0; i < s.size; i++)
        {
            if (t1[i] != t2[i])
                return false;
        }
    }
    return true;
}

FunString FunString::commonSuffix(const FunString &s) const
{
    char str[100];
    int index;
    for (int i = this->size, j = s.size; i >= 0 && i >= 0; i--, j--)
    {
        if (this->chars[i] == s.chars[j])
            index = i;
        else
        {
            break;
        }
        
    }

    int count = 0;
    for (int i = index; i < this->size; i++)
    {
        str[count] = this->chars[i];
        count++;
    }
    FunString fs(str, count);

    return fs;

}