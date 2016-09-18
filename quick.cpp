#include<iostream>
#include<ctime>
#include<fstream>
#include<vector>
using namespace std;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

 
// Driver program to test above functions
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
  
   
  quickSort(a, 0,99999);
    
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
     t<< "Quick sort timing :" << diff/CLOCKS_PER_SEC << "\n";
  }
  t.close();
  
  return 0;     
}




