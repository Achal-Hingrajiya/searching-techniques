#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
    int arr[N],i,search,flag=0;

    printf("Name: Hingrajiya Achal\nEn no.: 19012021012\n");
    printf("Practical8_1 : Sequential Search\n");

    printf("\nEnter the 10 elements of array:");

    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);


    printf("\nEnter element you want to search:");
    scanf("%d",&search);


    for (i = 0; i < N; i++)
    {
        if (arr[i] == search)
        {
            printf("\nElement %d is present at %d index.",search,i);
            flag=1;
        }

    }

    if (flag==0)
            printf("\nElement %d is not present in the Array.",search);




    return 0;
}
