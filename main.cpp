#include <iostream>
#include <cstdlib>
#include <vector>

void writeToFile(const char* nameOfFile = nullptr , int rangeMas = 100, int rangeRandomNumb = 1000)
{
    FILE* f;
    if(nameOfFile == nullptr)
    {
        f = fopen("text.txt", "w");
    }
    else
    {
        f = fopen(nameOfFile, "w");
    }
    if(f == nullptr)
    {
        return;
    }
    int itemCount = rand()%rangeMas;
    itemCount = (itemCount > 0 ? itemCount: (-1) * itemCount);
    for(int i=0; i < itemCount; ++i)
    {
        fprintf(f, "%d, ", rand()%rangeRandomNumb);
    }
    fclose(f);
}

std::vector<int>* readFromFile(const char* nameOfFile, std::vector<int>* vec)
{
    if(nameOfFile == nullptr)
    {
        // throw
        //return arr;
    }
    FILE* f;
    if((f = fopen(nameOfFile, "rt")) == nullptr)
    {
        //throw;
    }
    //    unsigned int count = 0;
    //    int c;
    //    while ((c = fgetc(f)) != EOF)
    //    {
    //        if(char(c) == ',' || char(c) == ';' || char(c) == ' ')
    //        {
    //            ++count;
    //        }
    //    }
    //    if(count == 0)
    //    {
    //        //throw
    //    }
    //    rewind(f);
    //    int tmp = 0;
    //    for(unsigned int i = 0; i < count; ++i)
    //    {
    //        fscanf(f, "%d, ", tmp);
    //        vec->push_back(tmp);
    //    }
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        fscanf(f, "%d, ", c);
        vec->push_back(c);
    }
    return vec;
}


//using namespace std;

int main()
{

    return 0;
}
