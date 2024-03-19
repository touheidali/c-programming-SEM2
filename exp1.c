#include <stdio.h>
#include <stdlib.h>
#define maxsize 1000 //not necessary just an example of macro

int list[maxsize],size; //global variable has default value 0 unlike local variables
void Create() {
    int i;
    printf("Enter the size of List: ");
    scanf("%d", &size);
    if (size > maxsize) {
        
        printf("Overflow !!!\n");
    } else {
        printf("Enter List Elements: \n");
        for (i = 0; i < size; i++) {
            scanf("%d", &list[i]);
        }
       
    }
}

void Display() {
    if (size == 0) {
        printf("List is Empty !!!\n");
    } else {
        printf("List Elements are: \n");
        int i;
        for (i = 0; i < size; i++) {
            printf("%d\t", list[i]);
        }
        printf("\n");
    }
}

void Insert()
{

    int pos, value, i;
    printf("Enter the index for inserting: ");
    scanf("%d", &pos);
    printf("Enter the element");
    scanf("%d", &value);
    if(pos<=size&&pos>=0&&size!=0)
    { for(i=size;i>=pos;i--)
    {
        list[i]=list[i-1];
    }
     list[pos] = value;
        (size)++;
    }
    else if(size==0)
    {
        printf("List Empty!!!\n");
    }
    else{
       printf("Invalid Position !!!\n");
    }
}
void Delete()
{
    if(size==0)
    {
        printf("List is Empty\n");
    }
    else{
        int pos,i;
        printf("Enter Index: ");
        scanf("%d", &pos);
        if(pos<=size&&pos>=0)
        {
            for(i=pos-1;i<size;i++)
            {
                list[i]=list[i+1];
            }
            size--;
            printf("Element Deleted!!!\n");
        }
        else{
            printf("Invalid Position!!!\n");
        }
    }
}
void Search()
{
    if(size==0)
    {
        printf("List is Empty!!!\n");
    }
   else{ int value, flag=0;
    printf("Enter the value to be searched: ");
    scanf("%d", &value);
   for(int i=0;i<size;i++)
   {
        if(list[i]==value)
        {
            printf("Element is at index %d\n", i);
            flag=1;
            break;
        }
   }
   if(flag==0)
   {
    printf("Element Not Found!!!\n");
   }
   }
}
void  main() {
Create();
Display();
Insert();
Display();
Delete();
Display();
Search();
}
