#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    ofstream g("numere2.txt");

    srand(time(NULL));

    g<<13<<endl;

    g<<10<<" "<<100<<endl;
    for(int i=0; i<10; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<10<<" "<<10000000<<endl;
    for(int i=0; i<10; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;

    g<<1000<<" "<<100<<endl;
    for(int i=0; i<1000; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<1000<<" "<<10000000<<endl;
    for(int i=0; i<1000; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;

    g<<100000<<" "<<100<<endl;
    for(int i=0; i<100000; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<100000<<" "<<10000000<<endl;
    for(int i=0; i<100000; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;

    g<<1000000<<" "<<100<<endl;
    for(int i=0; i<1000000; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<1000000<<" "<<10000000<<endl;
    for(int i=0; i<1000000; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;

    g<<10000000<<" "<<100<<endl;
    for(int i=0; i<10000000; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<10000000<<" "<<10000000<<endl;
    for(int i=0; i<10000000; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;

    g<<100000000<<" "<<100<<endl;
    for(int i=0; i<100000000; i++)
        g<<rand() % 100<<" ";
    g<<endl;

    g<<100000000<<" "<<10000000<<endl;
    for(int i=0; i<100000000; i++)
        g<<rand() % 10000000<<" ";
    g<<endl;*/

    g<<1000<<" "<<1000000000<<endl;
    for(int i=0; i<1000; i++)
        g<<rand() % 1000000000 + 1000000000<<" ";
    
    g<<endl;

    return 0;
}
