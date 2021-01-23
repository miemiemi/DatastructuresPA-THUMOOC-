#include <cstdio>

#define MAXSIZE 500000

using namespace std;

int *B = new int[MAXSIZE];

void merge(int * array, int lo, int mi ,int hi)
{
    int * A = array + lo;
    int lengthb = mi - lo;
    for(int i = 0 ; i < lengthb ; i++)
        B[i] = A[i];
    int lengthc = hi - mi;
    int * C = array + mi;
    for(int i = 0, j = 0, k = 0; j < lengthb;){
        if(k < lengthc && C[k] < B[j])  A[i++] = C[k++];
        if(lengthc <= k || B[j] <= C[k]) A[i++] = B[j++];
    }
}

void mergeSort(int * array, int lo, int hi)     //[lo,hi)
{
    if(hi - lo < 2)
        return;
    int mi = (lo + hi) >> 1;
    mergeSort(array,lo,mi);
    mergeSort(array,mi,hi);
    merge(array,lo,mi,hi);
}

int binarySearch(int * array, int e ,int lo , int hi)
{
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        e < array[mi] ? hi = mi : lo = mi + 1;
    }
    return --lo;        // lo - 1
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *array = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&array[i]);
    //sort
    mergeSort(array,0,n);
    //for(int i = 0; i < n; i++) printf("%d ",array[i]);

    int lborder,rborder,leftrank,rightrank;
    while (m--)
    {
        scanf("%d %d",&lborder,&rborder);
        leftrank = binarySearch(array,lborder,0,n);
        rightrank = binarySearch(array,rborder,0,n);
        if(leftrank < 0)
            ;
        else if(array[leftrank] == lborder)
            leftrank--;
        printf("%d\n",rightrank - leftrank);
    }
    
    return 0;
}