#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MALLOC(p,s)\
if(!(p = malloc(s))){\
	fprintf(stderr,"Insufficient memory");\
	exit(EXIT_FAILURE);\
}

typedef struct listNode { 
	int data;
	struct listNode *link;
} listNode;

listNode *first = NULL;

listNode *insert(int data ,listNode *link);
listNode * mysort(listNode *first, listNode *node);

listNode *printList(listNode *first);

int main(void)
{
	FILE *fp = fopen("input.txt","r");
	int data,i=0;

	while(i != 10){
		scanf("%d", &data);
		first = mysort(first ,insert(data,NULL));
      i++;
	}

	printList(first);

}

listNode * mysort(listNode *first, listNode *node)
{
	listNode *p , *q;

	p = q = first;
	//EMPTY
	if(!p){
		first = node;
		return first; 
	}
	//left
	if(node->data < p->data){
		node->link = p;
		first = node;
		return first;
	}
	//middle
	while(TRUE){
		if( p->data <= node->data && node->data < q->data){
			p->link = node;
			node->link = q;
			return first;
		}
		p = q;
		q = q->link;
		//Right
		if(!q){
			p -> link = node;
			return first;
		}
	}
	
}

listNode *insert(int data ,listNode *link)
{	
	listNode *temp;
	
	MALLOC(temp, sizeof(*temp)); //임이의 노드 temp를 temp만큼 메모리 다쓸떄 까지 무한
	temp -> data = data;
	temp -> link = link;

	return temp;
}


listNode *printList(listNode *first)
{
	for(; first; first = first->link) //first 초기 값부터 끝까지 출력
		printf("%d->",first -> data);
	printf("\n");

	return 0;
}