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
	for(i = 1;i <= cnt;i++){
		p = (node*)malloc(sizeof(node));
		if(p == NULL){
			printf("Failed");exit(EXIT_FAILURE);
		}
		
		p->data = i;
		p->next = NULL;
		
		if(head == NULL){
			head = p;
			pr = p;
		}else{
			pr->next = p;
			pr = p;
		}
		
	}
	return head;
}

void deleteNodeByPos(node*head,int pos){
	int i;
	node *p = head, *pr = head;
	for(i = 1;i < pos;i++){
		if(p->next != NULL){
			pr = p;
			p = p->next;
		}else{
			break;
		}
	}
	
	if(p->next == NULL){
		printf("EORRO : POSITION NOT FOUND !\n");
	}else{
		pr->next = p ->next;
		p ->next = NULL;
	
		free(p);
	}
	

}

void deleteNodeByData(node *head,int data){
	
	node *pr = head, *p = head;
	while(p->data != data){
		if(p->next != NULL){
			pr = p;
			p = p->next;
		}else {
			break;
		}
	}
	
	if(p->next == NULL){
		printf("ERROR : DATA NOT FOUND !\n");
	}else{
		pr-> next = p->next;
		p->next = NULL;
	
		free(p);
	}
	
}

void printLink(node*head){
	node *p = head;
	while(p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int cnt = 6;
	node *head = NULL;
	
	head = creatLink(head,cnt);
	printLink(head);
	
	deleteNodeByPos(head,7);
	printLink(head);
	
	deleteNodeByData(head,9);
	printLink(head); 
	return 0;
 } 
