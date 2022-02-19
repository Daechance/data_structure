#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p , s)\
	if(!(p = malloc(s))){\
		fprintf(stderr,"Insufficient memory");\
		exit(EXIT_FAILURE);\
	}

typedef struct listNode *listPointer;
typedef struct listNode{
	int data;
	listPointer link;
}listNode;


/*--------------functions--------*/
//creation
listPointer createNode(int data, listPointer link);
//insertion
void insert2First(listPointer *first, listPointer node);
void insertWithOrder(listPointer *first, listPointer *node); //순서에 맞게 리스트
//delete
int delete2First(listPointer *first);
int deleteItem(listPointer *first, int data);
// Display
void printList(listPointer first);
// Free
void freeList(listPointer first);

//Global variable
listPointer first = NULL;

int main(void)
{
//	first = createNode(10, createNode(20, createNode(30, NULL)));
//	printList(first);
//	putchar('\n');
//
//	insert2First(&first, createNode(5, NULL));
//	printList(first);
//	putchar('\n');
//	
//	if(!delete2First(&first)){ //delete가 0이라면 
//		printf("deleted!\n"); //지워졌다
//	}else{
//		printf("no element!\n"); //return값 0아니라면 dont have element
//	}if(!delete2First(&first)){
//		printf("deleted!\n");
//	}else{
//		printf("no element!\n");
//	}if(!delete2First(&first)){
//		printf("deleted!\n");
//	}else{
//		printf("no element!\n");
//	}if(!delete2First(&first)){
//		printf("deleted!\n");
//	}else{
//		printf("no element!\n");
//	}if(!delete2First(&first)){
//		printf("deleted!\n");
//	}else{
//		printf("no element!\n");
//	}

	insert2First(&first, createNode(5, NULL));
	printList(first);
	putchar('\n');

	insert2First(&first, createNode(10, NULL));
	printList(first);
	putchar('\n');

	insert2First(&first, createNode(20, NULL));
	printList(first);
	putchar('\n');

	insert2First(&first, createNode(30, NULL));
	printList(first);
	putchar('\n');

	insert2First(&first, createNode(40, NULL));
	printList(first);
	putchar('\n');

	if(!delete2First(&first)){ //delete가 0이라면 
		printf("deleted!\n"); //지워졌다
	}else{
		printf("no element!\n"); //return값 0아니라면 dont have element
	}
	printList(first);
	putchar('\n');
if(!delete2First(&first)){ //delete가 0이라면 
		printf("deleted!\n"); //지워졌다
	}else{
		printf("no element!\n"); //return값 0아니라면 dont have element
	}
	printList(first);
	putchar('\n');
	if(!delete2First(&first)){ //delete가 0이라면 
		printf("deleted!\n"); //지워졌다
	}else{
		printf("no element!\n"); //return값 0아니라면 dont have element
	}
	printList(first);
	putchar('\n');
	if(!delete2First(&first)){ //delete가 0이라면 
		printf("deleted!\n"); //지워졌다
	}else{
		printf("no element!\n"); //return값 0아니라면 dont have element
	}
	printList(first);
	putchar('\n');
	printf("stack top 구조랑 같음")
	printList(first);
	putchar('\n');
	freeList(first);

}

/*--------------functions--------*/
//creation
listPointer createNode(int data, listPointer link)
{
	listPointer temp;
	MALLOC(temp, sizeof(*temp));
	temp -> data = data;
	temp -> link = link;
	return temp;
}
//insertion
void insert2First(listPointer *first, listPointer node)
{
	//4가지 
	//0 중간에 있을때
	//1 비어있을떄 first null node link에 null
	//2 맨앞에 넣을떄
	//3 맨 뒤에 있을때
	node -> link = *first;
	*first = node;
}
void insertWithOrder(listPointer *first, listPointer *node)//순서에 맞게 리스트
{
	
} 
//delete
int delete2First(listPointer *first)
{
	listPointer temp = *first;
	if(*first){ //frist가 NULL이 아니라면
		*first = (*first) -> link; //괄호를 안하면 * 연산자 우선순위 때문에 link먼저 가르킴
		free(temp);	
		return 0;
	}

	//success
	return -1;
}
int deleteItem(listPointer *first, int data);
// Display
void printList(listPointer first)
{
	for( ; first; first = first->link){
		printf("%d ", first->data);
	}
}

// Free
void freeList(listPointer first)
{
	if(first){
		freeList(first->link); //다음칸씩가주면서 free
		free(first);
	}//재귀함수는 반복문과 똑같다
}
