#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#define size1 5
#define size2 100000
int main()
{
    int i,n;
    int array[size1],Array[size2];
    FILE *f,*f1,*f2;
    clock_t start,end,start1,end1;
    int total;
    printf("For 5 inputs:\n");
    printf("Enter the elements\n: ");
    for(i=0;i<size1;i++)
    {
        scanf("%d",&array[i]);
    }
    printf("\nBefore sorting:\n");
    for(i=0;i<size1;i++)
    {
        printf("%d\n ",array[i]);
    }

    sort(0,size1-1,array);
    printf("\nAfter sorting:\n");
    for(i=0;i<size1;i++)
    {
        printf("%d\n ",array[i]);
    }

    printf("\nFor 1M input:\n");
    f=fopen("input.txt","w");
    for(i=0;i<size2;i++)
    {
        fprintf(f,"%d\n ",rand());
    }
    fflush(f);
    fclose(f);
    f1=fopen("input.txt","r");
    for(i=0;i<size2;i++)
    {
        fscanf(f1,"%d\n",&Array[i]);
    }
    fclose(f1);
    f2=fopen("output.txt","w");
    fprintf(f2,"\nAfter sorting:\n");
    start = clock();
    sort(0,size2-1,Array);
    end = clock();
    for(i=0;i<size2;i++)
    {
        fprintf(f,"%d\n ",Array[i]);
    }
    total = ((double)(end-start))*1000/CLOCKS_PER_SEC;
    printf("\nExecution time for 1M(in millisec): %d millisec\n",total);
    fclose(f2);

    return 0;
}


void merge(int left,int mid,int right,int array[])
{
    int a,b,c,N1,N2,x,y;
    N1=mid-left+1;
    N2=right-mid;
    int l_tree[N1],r_tree[N2];
    for(x=0;x<N1;x++)
    {
        l_tree[x] = array[left+x];
    }
    for(y=0;y<N2;y++)
    {
        r_tree[y] = array[mid+y+1];
    }
    for(a=0,b=0,c=left;a<N1 && b<N2;c++)
    {
        if(l_tree[a]<r_tree[b])
        {
            array[c]=l_tree[a];
            a++;
        }
        else
        {
            array[c]=r_tree[b];
            b++;
        }
    }
    while(a<N1)
    {
            array[c]=l_tree[a];
            a++;
            c++;
    }
    while(b<N2)
    {
            array[c]=r_tree[b];
            b++;
            c++;
    }
}
void sort(int first,int last,int Array[])
{
    int mid;
    if(first<last)
    {
        mid=(first+last)/2;
        sort(first,mid,Array);
        sort(mid+1,last,Array);
        merge(first,mid,last,Array);
    }
}


