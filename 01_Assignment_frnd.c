/*1. Write a Menu Driven C Program to create an integer array and populate it with some
data. Then perform the following operations with user choice:
a) Insert an element: i) at beginning, ii) at end iii) at the any position of the array.
b) Delete an element from i) beginning ii) from end iii) from a given position of the array.
c) Replace the element of a given position with another number.
d) Search if an element exists in the list (using linear search).
e) Display the array elements.*/
#include<stdio.h>

int main()
{
  int arr[20],i,n;int ch,c,position;
  printf("Enter the size of the array: ");
  scanf("%d",&n);
 for(i=0;i<n;i++)
  {
    printf("ENTER THE ARRAY:");
    scanf("%d",&arr[i]);

  }
  printf("\nTHe original array is :");
  for(i=0;i<n;i++)
  {
    printf(" %d",arr[i]);
       
  } 

  printf("\nEnter the choice:\n 1) Insert an element: \n \t 1) at beginning, \n \t 2) at the any position of the array  \n \t 3) at the end.\n2) Delete an element from: \n \t 1) beginning  \n \t 2) from end  \n \t 3) from a given position of the array.\n 3) Replace the element of a given position with another number.\n 4) Search if an element exists in the list (using linear search)\n Enter your choice among these:  ");
  scanf(" %d",&ch);
  switch (ch)
  {
  case 1:
    printf("Insert an element: \n \t 1) at beginning, \n \t 2) at any positions    \n \t 3) at the end.\n \t Enter your choice :  ");
    scanf("\n %d",&c);
    switch(c)
    {
      case 1:
        printf("ENtered to insert the element at the beginning:\n");
        int val;
        printf("Enter the value to insert:");
        scanf("%d",&val);
        if(n<20)
        {
          for(i=n-1;i>=0;i--)
          {
            arr[i+1]=arr[i];

          }
          arr[0]=val;
        }
        for(i=0;i<=n;i++)
        {
          printf(" %d",arr[i]);
        }
        break;
      case 2:
          printf("ENtered to insert the element at any position in the array:\n");
          int va,pos;
          printf("Enter the value to insert:");
          scanf("%d",&va);
          printf("Enter the position to insert:");
          scanf("%d",&pos);
          if(n < 20 && pos >= 0 && pos <= n) 
        {
       
          for(i = n; i > pos; i--)
           {
            arr[i] = arr[i - 1];
        }
        arr[pos] = va;
        n++;
        for(i=0;i<n;i++)
        {
          printf(" %d",arr[i]);
        }
       }
        break;
    case 3:
          printf("you have entered to add an element at the end of the array :( \n");
          int v;

          printf("Enter the value to insert the element:");
          scanf("%d",&v);
          if(n>20)
          {
            printf("housefull array: ");
            return 1;

          }
          if(n<20)
          {
            arr[n]=v;
            n++;

          }
          else
          {
            printf("Array is full :( ");
          }

          for(i=0;i<n;i++)
        {
          printf(" %d",arr[i]);
        }      
      
        break;
      default:
          printf("invalid choice :(");
      break;

      
    }
    break;
  case 2:
    printf("You have entered to Delete an element from: \n \t 1) beginning  \n \t 2) from end  \n \t 3) from a given position of the array.\n ");
    int x;
    printf("Enter your choice:");
    scanf("%d",&x);
    switch(x)
    {
      case 1:
        printf("you have entered to delete an element from the beginning: ");
        if(n>0)
        {
          for(i=0;i<n-1;i++)
          {
            arr[i]=arr[i+1];

          }
          n--;

        }

        else
        {
          printf("Empty");
        }

        printf("We get the array as:\n ");
        for(i=0;i<n;i++)
        {
          printf(" %d",arr[i]);
        }
        
        
        printf("\n");

    break;

    case 2:
        printf("Entered to delete from the end:\n");
        if(n>0)
        {
          n--;
          
        }
        printf("UPDATED ARRAY:");
        for(i=0;i<n;i++)
        {
          printf(" %d",arr[i]);

        }printf("\n");

        break;
    case 3:
      
    printf("Enter the position of the element to delete (0 to %d): ", n- 1);
    scanf("%d", &position);

    if (position < 0 || position >= n) 
    {
        printf("Invalid position. Element cannot be deleted.\n");
    }
    else
     {
        
        for (i = position; i < n - 1; ++i)
         {
            arr[i] = arr[i + 1];
         }
      
        n--;
    }
    printf("Updated Array: ");
    for (i = 0; i < n; ++i)
     {
        printf("%d ", arr[i]);
     }
    printf("\n");
    break;
    default:
    printf("Invalid");
    
    }

    break;

    case 3:


    printf("you have entered to replace the element of a given position with another number.\n");
    int p;
    printf("Enter the position of the element to replace (0 to %d): ", n - 1);
    scanf("%d", &p);

    if (p< 0 || p >= n) 
    {
        printf("Invalid position. .\n");
    } 
    else 
    {
        int newNumber;
        printf("Enter the new number: ");
        scanf("%d", &newNumber);

       
        arr[p] = newNumber;
    }

    printf("Updated Array: ");
    for (i = 0; i < n; i++) 
    {
        printf(" %d ", arr[i]);   
    }
        printf("\n");

    break;


  case 4:
    printf("You have entered to search an element:\n");

    int t,f=-1;
    printf("Enter the number to search :");
    scanf("%d",&t);
     for (i = 0; i < n; ++i) 
     {
        if (arr[i] == t)
         {
            f = i;  
            break;  
         }
    }

    if (f!= -1) 
    {
        printf("%d found at index %d.\n", t, f);
    }
    else 
    {
        printf("%d not found in the array.\n", t);
    }

    break;
  
  default:

  printf("Invalid choice: ");

    break;
  
  }
  return 0;
}