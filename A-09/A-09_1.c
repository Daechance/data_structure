#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
}listNode;
listPointer first = NULL;

#define MALLOC(p, s) \
	if(!((p) = malloc( s ))){	\
		fprintf(stderr, "Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

void insert(listPointer *first, listPointer x, int data);
void delete(listPointer *first, listPointer trail, listPointer x);
void find(listPointer first, listPointer *x, int data);
void printList(listPointer first);

int main(void)
{
	int data;
	listPointer x, trail, curr, ffirst;

	FILE *fp = fopen("input.txt","r");

	if(fp == NULL){
		fprintf(stderr,"cannot open file");
		exit(EXIT_FAILURE);
	}

	fscanf(fp , "%d", &data);

	while(!feof(fp)){
		find(first, &x, data);
		insert(&first, x, data);
		fscanf(fp, "%d", &data);
	}

	printf("\n\nThe ordered list contains: \n");
	printList(first);
	
	curr = ffirst = first;
	trail = NULL;

	while (curr != NULL)
	{
		if ((curr->data) < 20) {
			x = curr;

			delete(&first, trail, x);
			if (ffirst != first) {
				trail = NULL;
				curr = first;
				ffirst = first;
			}
			else
				curr = trail->link;

		}
		else
		{
			trail = curr;
			curr = curr->link;
		}
	}

	printf("\nAfter deleting nodes with odd value\n");
	printList(first);

	while (curr != NULL) {
		listPointer nxt = curr->link;
		free(curr);
		curr = nxt;
	}
	free(first);

	fclose(fp);

	return 0;
}

void find(listPointer first, listPointer *x, int data)
{	
	listPointer trav = first;

	if (first == NULL){ //empty list
		*x = first; 
	}else{
		for (; trav; trav = trav->link){ //처음부터 끝까지 돌면서
			if (data > trav->data) //만약 data값이 도는 trav data보다 크면
				*x = trav; //tave를 x에 역참조
			else{ 
				if (first == trav) //만약 두개가 같다면
					*x = NULL; //NULL
				break;//작다면 그냥 해주면 정렬끝
			}
		}
	}
	
}

void insert(listPointer *first, listPointer x, int data)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp)); //임이의 노드 temp를 temp만큼 메모리 다쓸떄 까지 무한
	temp -> data = data;

	if(*first == NULL){ //비어 있다면
		temp -> link = NULL;
		*first = temp;
	}else{
		if(x == NULL){ //비어있지 않지만 1번
			temp -> link = *first;
			*first = temp;
		}else{ //비어있지 않지만 2번
			temp -> link = x -> link;
			x -> link = temp;
		}
	}
}

void delete(listPointer *first, listPointer trail, listPointer x)
{
	if (trail)
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}



void printList(listPointer first)
{
	printf("(노드주소, 데이터 필드, 링크값)\n");
	for( ; first; first = first->link)
		printf("(%p : 노드주소, 데이터 필드 : %d,  링크값 : %p)\n", first, first->data, first->link);
	printf("\n");

}


//The ordered list contains: 
//(노드주소, 데이터 필드, 링크값)
//(0x6000006640e0 : 노드주소, 데이터 필드 : 7,  링크값 : 0x600000664070)
//(0x600000664070 : 노드주소, 데이터 필드 : 19,  링크값 : 0x600000664060)
//(0x600000664060 : 노드주소, 데이터 필드 : 20,  링크값 : 0x6000006640c0)
//(0x6000006640c0 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664090)
//(0x600000664090 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664050)
//(0x600000664050 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664030)
//(0x600000664030 : 노드주소, 데이터 필드 : 50,  링크값 : 0x6000006640a0)
//(0x6000006640a0 : 노드주소, 데이터 필드 : 55,  링크값 : 0x6000006640b0)
//(0x6000006640b0 : 노드주소, 데이터 필드 : 77,  링크값 : 0x600000664040)
//(0x600000664040 : 노드주소, 데이터 필드 : 80,  링크값 : 0x6000006640d0)
//(0x6000006640d0 : 노드주소, 데이터 필드 : 87,  링크값 : 0x600000664080)
//(0x600000664080 : 노드주소, 데이터 필드 : 90,  링크값 : 0x0)
//
//
//After deleting nodes with odd value
//(노드주소, 데이터 필드, 링크값)
//(0x600000664060 : 노드주소, 데이터 필드 : 20,  링크값 : 0x6000006640c0)
//(0x6000006640c0 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664090)
//(0x600000664090 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664050)
//(0x600000664050 : 노드주소, 데이터 필드 : 30,  링크값 : 0x600000664030)
//(0x600000664030 : 노드주소, 데이터 필드 : 50,  링크값 : 0x6000006640a0)
//(0x6000006640a0 : 노드주소, 데이터 필드 : 55,  링크값 : 0x6000006640b0)
//(0x6000006640b0 : 노드주소, 데이터 필드 : 77,  링크값 : 0x600000664040)
//(0x600000664040 : 노드주소, 데이터 필드 : 80,  링크값 : 0x6000006640d0)
//(0x6000006640d0 : 노드주소, 데이터 필드 : 87,  링크값 : 0x600000664080)
//(0x600000664080 : 노드주소, 데이터 필드 : 90,  링크값 : 0x0)