#include <iostream>
#include <cstdlib>


//using namespace std;

int main()
{
    FILE *f;
    unsigned int numberItems = rand()%200;
    if((f = fopen("text.txt", "w")) != nullptr)
    {
        for(unsigned int i=0; i<numberItems; ++i)
        {
            fprintf(f, "%d, ", rand()%1000);
        }
        fclose(f);
    }
    else
    {
        std::cout << "cant open file!" <<std::endl;
        return 1;
    }
    unsigned int count = 0;
    char c;
    if((f = fopen("text.txt", "rt")) != nullptr)
    {
        while((c = fgetc(f)) != EOF)
        {
            if(c == ',')
            {
                count++;
            }
        }
        if(count == 0)
        {
            std::cout << "no numbers in file!" << std::endl;
        }
        fclose(f);
    }
    if((f = fopen("text.txt", "rt")) != nullptr)
    {
        int arr[count];
        for(unsigned int i = 0; i < count; ++i)
        {
            fscanf(f, "%d, ", &arr[i]);
            std::cout << arr[i] << std::endl;
        }
        system("pause");
    }
    else
    {
        std::cout << "cant open file!" <<std::endl;
        return 1;
    }
 //   cout << "Hello World!" << endl;
    return 0;
}
