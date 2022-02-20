#include <stdio.h>
#include <stdlib.h>
 // 12 분부터 보기
#define TRUE 1
#define FALSE 0
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
void insertWithOrder(listPointer *first, listPointer node); //순서에 맞게 리스트
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
	insertWithOrder(&first, createNode(5, NULL));
	insertWithOrder(&first, createNode(3, NULL));
	insertWithOrder(&first, createNode(1, NULL));
	insertWithOrder(&first, createNode(3, NULL));
	insertWithOrder(&first, createNode(3, NULL));
	insertWithOrder(&first, createNode(-4, NULL));
	insertWithOrder(&first, createNode(3453, NULL));

	if(!deleteItem(&first, 3))
		printf("Success\n");
	
	printList(first);
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
void insertWithOrder(listPointer *first, listPointer node)//순서에 맞게 리스트
{
	listPointer p, q;

	p = q = *first;

    //empty
    if(!p){
        *first = node;
        return;
    }

    //left
    p = q = *first;
    if(node->data < p -> data){
        node->link = p;
        *first = node;
        return;
    }
    while(TRUE)
    {   
        //middle
        if( p->data <= node-> data && node->data < q->data){
            p->link = node;
            node->link = q;
            return;
        }
        p = q;
        q = q->link;
        //right
        if(!q){ //q 가 null일 경우
            p -> link = node;
            return;
        }
    }
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
int deleteItem(listPointer *first, int data)
{
	listPointer p, q;

	p = q = *first;

	//empty data
	if(!p) return -1;
	//left
	if(p -> data == data){
		*first = (*first)->link;
		free(q);
		return 0;
	}

	while(TRUE)
	{	
		//중간에 data있는경우
		if( q -> data == data){
			p -> link = q -> link;

			free(q);
			return 0;
		}
		p = q;
		q = q -> link;

		//No data 
		if(!p) return -1;
	}
}
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
