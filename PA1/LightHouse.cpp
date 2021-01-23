#include <cstdio>
#include <stdlib.h>

#define MAXSIZE 4000000

using namespace std;

//其实只有计数需要用到__int64 但是这个在Tsinghua OJ里编译不过去（）
struct Point
{
    int x;
    int y;
}points[MAXSIZE];


long cnt = 0;
int ysequence[MAXSIZE];
int B[MAXSIZE];

void merge(int * array, int lo, int mi ,int hi)
{
    int * A = array + lo;
    int lengthb = mi - lo;
    for(int i = 0 ; i < lengthb ; i++)
        B[i] = A[i];
    int lengthc = hi - mi;
    int * C = array + mi;
    for(int i = 0, j = 0, k = 0; j < lengthb;){
        if(k < lengthc && C[k] < B[j]) 
            A[i++] = C[k++];
        if(lengthc <= k || B[j] <= C[k]){
            A[i++] = B[j++];
            //两对有序序列中，每个元素和自己序列中元素的顺序对已经计算完成，只需计算和另外一个有序序列中元素的顺序对
            if(k < lengthc)                 //统计顺序对数 
                cnt += lengthc - k;
        }
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

//按照 x 的值从小到大将结构体排序
int cmp(const void *a,const void *b)
{
     return (*(Point*)a).x > (*(Point*)b).x ? 1 : -1;
}

int main()
{

    //按照x坐标排序后 y的顺序对即可相互照亮
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d %d",&points[i].x,&points[i].y);
    //sort
    qsort(points,n,sizeof(points[0]),cmp);
    //for(int i = 0; i < n; i++) printf("%d",points[i].x);
    for(int i = 0; i < n; i++)
        ysequence[i] = points[i].y;
    //计算ysequence中的顺序对数
    mergeSort(ysequence,0,n);
	printf("%ld\n",cnt);
    return 0;
}