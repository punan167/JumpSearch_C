#include "stdio.h"
#include "math.h"
int min(int first,int second)
{
    if (second > first)
    {
        return first;
    }else
    {
        return second;
    }
}

int jumpSearch(int arr[] , int size ,int key,int step)
{
    int previous = 0;
    int betweenValue = 0;
    int middle = 0;
    int conststep = step+1;
    while (arr[min(step, size)-1] < key){
        previous = step ;
        middle = conststep / 2;
        betweenValue = (previous-middle) ;
        step += step;

        printf("Value between JUMP step is %d\n",arr[betweenValue]);
        if(previous>=size)
        {
            return -1;
        }
    }
    if(arr[min(step, size)-1] == key)
    {
        printf("Founded Directly!\n");
        return key-1;
    }
    for(int j =previous ; j < step ; j++ ){
        if(arr[j]==key){
            return j;
        }
    }
    return -1;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};

    int size = sizeof (arr)/sizeof (arr[0]);

    int defaultstep = size / 3;

    int tofind;
    printf("Enter a Number : ");
    scanf("%d",&tofind);

    printf("JUMP Step : %d \n",defaultstep);
    int indexNumber = jumpSearch(arr,size,tofind,defaultstep);

    if(indexNumber != -1){
        printf("We found data : %d at index: %d \n",arr[indexNumber],indexNumber);
    } else{
        printf("Not found!!");
    }

    return 0;
}

