#include<iostream>
#include<vector>
#include<fstream>
using namespace std;


int main()
{ clock_t t1,t2;
  long long min ,i,j;
  vector<int> a;                  // reading file
  int num;
  std::ifstream in("input.txt");
  while(in >> num)
  {  
     a.push_back(num);
  }
  in.close();  
  t1=clock();                   //reading done
  for(i=0;i<a.size();i++)
     { min=i;
       for(j=i+1;j<a.size();j++)
          {
            if(a[j]<a[min])
              {
                 min= j;
              }
          }   
       if(i!=min)
       {
        a[min]=a[min] + a[i];
	a[i] = a[min] - a[i];
	a[min] = a[min] - a[i];

       }
      

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
     t<< "Selection sort timing for  " << a.size()<< "inputs :"<< diff/CLOCKS_PER_SEC << "\n";
  }
  t.close();
  
  return 0;
}

