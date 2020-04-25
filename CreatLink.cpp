#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;

node *creatLink(node*head,int cnt){	
	node *pr,*p;
	int i;
	
	pr = (node*)malloc(sizeof(node));
	if(pr == NULL){
		printf("Failed!");exit(EXIT_FAILURE);
	}
	pr->data = cnt;
	pr->next = NULL;
	
	head = pr;
	
	for(i = 1;i <= cnt;i++){
		p = (node*)malloc(sizeof(node));
		if(p == NULL){
			printf("Failed!");exit(EXIT_FAILURE);
		}
		p->data = i;
		p->next = NULL;
		
		pr->next = p;
		pr = p;
		
	}
	return head;
}

void printLink(node*head){
	node *p = head;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

int main()
{
	node*head;
	int cnt = 6;
	head = creatLink(head,cnt);
	printLink(head);
	
	
	
	return 0;
 } 
