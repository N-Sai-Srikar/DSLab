#include<stdio.h>
#include<stdlib.h>
 struct stack
 {
 	int data;
 	struct stack *next;
 };
struct stack *top=NULL;
struct stack *push(	struct stack *top,int val)
{
    struct stack *ptr = malloc(sizeof(struct stack));
    ptr->data = val;
    ptr->next = top;
    top=ptr;
    return top;
}	  
struct stack *pop(	struct stack *top)
{
	struct stack *ptr =top;
	if(top==NULL)
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		top=top->next;
		printf("\n the value being deleted is:%d",ptr->data);
		free(ptr);
		return top;
	}
}
int peek(struct stack *top)	
{
	return(top==NULL)?-1:top->data;
}
struct stack *display(struct stack *top)
{
	struct stack *ptr = top;
	if(top==NULL)
	{
		printf("\n stackis empty");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("\n%d",ptr->data);
			ptr = ptr->next;
		}
	}
		return top;
}
int main()
{
	int val,option;
	do
	{
		printf("******MAINMENU*******");
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.PEEK");
		printf("\n4.DISPLAY");
		printf("\n5.EXIT");
		printf("\nENTER YOUR OPTION:");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1:
				printf("\nEnter the number to be pushed on to stack:");
				scanf("%d",&val);
				top = push(top,val);
				break;
			case 2:
			    top = pop(top);
			    break;
			case 3:
			val = peek(top);
			if (val!= -1) 
			    printf("\n The value at the top of stack is :%d",val); 
			else
			    printf("\nstack is empty");
			break;
	        case 4:
	        	top = display(top);
	        	break;
	        }
	    }
		while (option !=5);
	    return 0;
		}


						  				
		

	
		
