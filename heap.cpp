#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;
void swap(int * a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 ; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}


int main()
{
    clock_t t1,t2;
    int a[100000];
    int n,i,j;
    ifstream file("input.txt");
    if(file.is_open())
    {
        

        for(int i = 0; i < 100000; ++i)
        {
            file >> a[i];
        }
    }
  t1=clock();               
  
   
  heapSort(a, 99999);
    
   t2=clock();
  ofstream out("output.txt");            // output in a seprate file
  if(out.is_open())
  {
     for(i=0;i<100000;i++)
         out << a[i] << "\n";
  }
  out.close();
  
  float diff=((float)t2-(float)t1);
  std::ofstream t("time.txt",ofstream ::app);            // output in a seprate file
  if(t.is_open())
  {
     t<< "heap sort timing :" << diff/CLOCKS_PER_SEC << "\n";
  }
  t.close();
  
  return 0;     
    
      
    
}
