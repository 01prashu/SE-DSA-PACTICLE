// Read the marks obtained by second year in an online examination of perticular subject .Find min and max marks using heap data structure
#include <iostream>
using namespace std;

class Maxheap
{
public:
    int arr[100];
    int size;
    Maxheap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insertEle(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
        
    }
    void display()
    {
        for(int i=1;i<=size;i++)
        {
            std ::cout<<arr[i]<<" ";
        }
    }
};
class Minheap
{
public:
    int arr[100];
    int size;
    Minheap()
    {
        arr[0]=-1;
        size=0;
    }
    void insertEle(int val)
    {
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index > 1)
        {
            int parent=index/2;
            if(arr[parent] > arr[index])
            {
                swap(arr[parent] ,arr[index]);
            }
            else
            {
                return;
            }
        }
    
    }
    void display()
    {
        for(int i=1;i<=size;i++)
        {
            std ::cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    Maxheap h;
    Minheap h1;
    int ele;
    std ::cout<<"Enter Number of element you want to insert"<<endl;
    std ::cin>>ele;
    for(int i=0;i<ele;i++)
    {
        int a;
        std ::cin>>a;
        h.insertEle(a);
        h1.insertEle(a);
    }
    h.display();
    h1.display();
    
    
    return 0;
}