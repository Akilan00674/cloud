#include<iostream>
using namespace std;

struct pq
{
    int* arr;
    int* priority;  
    int max;
    int size;
};

void enq(pq& q,int val,int prior)
{
    if(q.size==q.max-1)
    {
        cout<<"full";
    }
    else
    {
        int i = q.size;
        while(i>=0 && prior < q.priority[i]) //
        {
            q.arr[i+1]=q.arr[i];
            q.priority[i+1]=q.priority[i];
            i--;
        }
        q.arr[i+1]=val;
        q.priority[i+1] = prior;
        q.size++;
    }
}
void dq(pq q)
{
    if(q.size == -1)
    {
        cout<<"empty";
    }
    else
    {
        q.size--;
        
        cout<<q.arr[0];
        
        for(int i = 0 ;i<=q.size;i++)
        {
            q.arr[i]=q.arr[i+1];
            q.priority[i]=q.priority[i+1];
        }
        
    }
}

void dis(pq q)
{
    for(int i = 0;i<=q.size;i++)
    {
        cout<<q.arr[i]<<endl;
    }
}


int main()
{
    pq q;
    q.arr = new int[5];
    q.priority = new int[5];
    q.size=-1;
    q.max=5;
    
    enq(q,11,5);
    enq(q,12,2);
    enq(q,13,1);
    enq(q,14,3);
    enq(q,15,4);
    
    dis(q);
    
    return 0;    
}
