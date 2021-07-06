#include<stdio.h>
#include<stdlib.h>
#define N 10
int main()
{
    int arr[N],i,search,low,middle,high,flag=0;

    printf("Name: Hingrajiya Achal\nEn no.: 19012021012\n");
    printf("Practical8_2 : Binary Search\n");

    printf("\nEnter the 10 elements of array:");

    for(i=0;i<N;i++)
        scanf("%d",&arr[i]);


    printf("\nEnter element you want to search:");
    scanf("%d",&search);

    low=0;
    high=N-1;

    while(low<=high)
    {
        middle=(low+high)/2;

        if(search<arr[middle])
            high=middle-1;

        else if(search>arr[middle])
            low=middle+1;

        else
        {
            printf("\nElement %d is present at %d index.",search,middle);
            flag=1;
            break;
        }



    }//while

    if(flag==0)
        printf("\nElement %d is not present in the Array.",search);



    return 0;
}
