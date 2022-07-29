#include<stdio.h>

#define size 10  //size of stack is initialized to 10
 
int stack[size],top,ch;
 
 void push();         //function to insert element to stack
 void pop();          //function to delete the top element
 void peek();         //function to display the top of stack
 void display();      //function to display the elements of stack
 
 void main()
 {
    printf("\tImplementation of stack using arrays\n");
    printf("\n   Size of stack: %d\n",size);
        
        top = -1;
        
        do{
            printf("\n\tPossible operations on stack: \n");
            printf("\t\t  1.Push\n");
            printf("\t\t  2.Pop\n");
            printf("\t\t  3.Peek\n");
            printf("\t\t  4.Display\n");
            printf("\t\t  5.Exit\n");
            
            printf("\n\tEnter the choice: ");
            scanf("%d", &ch);
            printf("\n");
        
          switch(ch)
            {
                case 1: push();
	                    break;
                case 2: pop();
                        break;
                case 3: peek();
                        break;
                case 4: display();
	                    break;
                case 5:
                  {
	                  printf("\t  --> Exited from stack program!!\n");
	                  break;
                  }
                default:
	                  printf("  --> Wrong Choice, Enter a valid choice!!\n");
            }
          
          }while (ch != 5); 
  }

void push()  //push() definition
{
    if(top>=size - 1)
        printf("   Stack Overflow--Cannot insert element!!\n");
    
    else
        {
            top++;
            printf("  Enter the element to be inserted: ");
            scanf("%d", &stack[top]);
            printf("   --> Element %d is pushed to the stack\n", stack[top]);
        }

}

void pop()  //pop() definition
{
    if(top<=-1)
        printf("   Stack Underflow--Cannot delete element!!\n");
    
    else    
        {
            printf("   --> Element %d is deleted from the stack\n", stack[top]);
            top--;
        }

}

void peek() //peek() definition
{
    if(top<0)
        printf("  --> Stack is empty!!\n");
    
    else
    {   
        printf("   --> Top of stack: %d\n",stack[top]);
    }
}

void display()
{
    if(top<0)
        printf("  --> Stack is empty!!\n");
    
    else
        {
        int t=top;
        printf("  Elements in the stack: \n");
            
                while (t>= 0)
                {
                    printf("\t\t%d\n", stack[t]);
                    t--;
                }
        }
}
