#include<iostream>
#include<ctime>
#include<vector>
#include<fstream>
using namespace std;
int main()
{
	clock_t t1,t2;
	vector<int> a;
	int n,i,j,flag=0;
	ifstream in("input.txt");
        
    
    while(in>>n)
    {

      a.push_back(n);
    }
    in.close();
    t1=clock();
    for(i=0;i<a.size();i++)
    {
      for(j=0;(j<a.size()-i);j++)
      {
         if (a[j]>a[j+1])
         {  flag=1;
            a[i]=a[i]+a[j];
            a[j]=a[i]-a[j];
            a[i]=a[i]-a[j];
         }

      } 
     if(flag==0)
       break;
    }
    

    t2=clock();
    
    ofstream out("output.txt");

     for(i=0;i<a.size();i++)
         out << a[i] << "\n";
  
   
    out.close();
     float diff=((float)t2-(float)t1);
  ofstream t("time.txt",ofstream ::app);            // output in a seprate file
  if(t.is_open())
  {
     t<< "Bubble  sort timing for  "<< a.size() << " inputs " << diff/CLOCKS_PER_SEC << "\n";
  }
  t.close();
     return 0;
     

}
