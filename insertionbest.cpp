#include<iostream>
#include<ctime>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	int i,v; int j=0;
	clock_t t1,t2;
	ifstream in("input.txt");
	vector<int> a;
	int num;
	while(in >> num)
	{
		a.push_back(num);

	}
	in.close();
	t1=clock();
	for(i=0;i<a.size();i++)
	{
		v=a[i];
        j=i;
		while(a[j-1]>v && j>=1)
		{
			a[j]=a[j-1];
			j--;
		}
		a[j]=v;

	}
	 t2=clock();
  ofstream out("output.txt");            // output in a seprate file
  if(out.is_open())
  {
     for(i=0;i<a.size();i++)
         out << a[i] << "\n";
  }
  out.close();
  
  float diff=((float)t2-(float)t1);
  std::ofstream t("time.txt",ofstream ::app);            // output in a seprate file
  if(t.is_open())
  {
     t<< "Insertion sort timing for best   " << a.size()<< "inputs :"<< diff/CLOCKS_PER_SEC << "\n";
  }
  t.close();
  
  return 0;
}




   



