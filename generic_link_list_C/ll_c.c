#include<stdio.h>
#include<stdlib.h>


struct Node {
	struct Node *next;
	void *value;
};

struct Node *head=NULL;
void push(struct Node *);

void insert(char type)
{
	struct Node* n = malloc(sizeof(struct Node));
	if(type == 'l')
	{
		long long i;
		scanf("%lld",&i);
		n->value = &i;
	}
	else if(type =='d')
	{
		double i;
		scanf("%lf",&i);
		n->value = &i;
	}
	else if(type == 'i')
	{
		int i;
		scanf("%d",&i);
		n->value = &i;
	}
	else if(type == 'c')
	{
		char i;
		scanf("%c",&i);
		n->value = &i;
	}
	else if(type == 'f')
	{
		float i;
		scanf("%f", &i);
		n->value = &i;
	}
	push(n);
}

void delete(int index)
{
	if(index==0)
	{
		head = head->next;
	}
	else
	{
		struct Node *n = head;
		int count = 1;
		while(count!=index)
		{
			count++;
			n=n->next;
		}
		n->next = n->next->next;
	}
}

void *access(int index)
{
	int count = 0;
	struct Node* n = head;
	while(count !=index)
	{
		n=n->next;
		count++;
	}
	return n->value;
}

void push(struct Node* n)
{
	if(head==NULL)
        {
                head = n;
                head->next = NULL;
        }
        else
        {
                struct Node *t = head;
                while(t->next != NULL)
                {
                        t=t->next;
                }
                t->next =n;
                n->next = NULL;
        }

}

int main()
{
	return 0;
}
