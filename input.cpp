#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
using namespace std;

int main()
{   int num;
	cout << "how many numbers u wanted to sort";
    cin >> num;
	long n;
	int no;
	time_t sec;
	time(&sec);
	srand((unsigned int) sec);
	ofstream out("input.txt"); 
	           // output in a seprate file
    {
    if(out.is_open())
	for(n=0;n<num;n++)
	{
		no=rand()%10000;
		out <<no <<"\n";
      
	}
	}
    out.close();
    return 0;
}
