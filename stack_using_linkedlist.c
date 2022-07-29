#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int info;
    struct stack *link;
    
}*top=NULL,*new,*temp;

void push();
void pop();
void display();
struct stack *allocate_node();

int ch;

void main()
{
    printf("\tImplementation of stack using linked list\n");
    
    do{
        printf("\n   Stack Operations: \n\n");
        printf("\t1.Push\n");
        printf("\t2.Pop\n");
        printf("\t3.Display\n");
        printf("\t4.Exit\n");
        
        printf("\n Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: push();
                    break;
            
            case 2: pop();
                    break;

            case 3: display();
                    break;
            
            case 4: printf("\n   --> Exited from program\n");
                    break;
        
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
        
    }while(ch!=4);
    
}

struct stack *allocate_node()
{
    new = (struct stack *)malloc(sizeof(struct stack));
    
    if(new == NULL)
    {
        printf("\n   --> Memory allocation for a new node failed!!\n");
        exit(1);
    }
    
    else    
        return new;
}

void push()
{
    int item;

    printf("\n Enter the element to be inserted: ");
    scanf("%d",&item);
    
    new = allocate_node();
    new->info=item;

    if(top==NULL)
    {
        new->link=NULL;
        top=new;
    }
    
    else
    {
        new->link=top;
        top=new;
    }
    
    printf("\n   --> Element %d is pushed to stack\n",item);
}

void pop()
{
    int item;
    
    temp=top;
    
    if(top==NULL)
        printf("\n   --> Stack Underflow, Cannot delete element\n");

    else
    {
        item=temp->info;
        top=temp->link;
        printf("\n   --> Element %d is deleted from stack\n",item);
        free(temp);
    }
}

void display()
{
    temp=top;
    
    if(temp==NULL)
        printf("\n   --> Stack is empty\n");

    else
    {
        printf("\n   Elements in the stack: \n\n"); 
        
        while(temp!=NULL)
        {
            printf("\t   %d\n",temp->info);
            temp=temp->link;
        }
    }
}
