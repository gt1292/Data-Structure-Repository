//////////////////////////////////////
//program to write summation of array
/////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>

int Sumation(int Arr[],int iLength)
{
   int iSum =0 ,iCnt = 0;

   for(iCnt = 0; iCnt< iLength; iCnt++) 
   {
       iSum = iSum +Arr[iCnt];
   }
   return iSum;
}

int main()
{
    int iSize = 0;
    int *ptr = NULL;
    int iCnt = 0, iRet = 0;

    printf("Enter the number of elements :");
    scanf("%d",&iSize);

    ptr = (int *)malloc(sizeof(int)*iSize);

    printf("enter the value of array :\n");

    for(iCnt = 0; iCnt< iSize; iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    iRet = Sumation(ptr,iSize);

    printf("Addition is :%d\n",iRet);

    free(ptr);

    return 0;
}