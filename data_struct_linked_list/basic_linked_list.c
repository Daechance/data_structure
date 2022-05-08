#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * link;
}Node;

typedef struct List
{
	Node* head;
	Node* cur;
	Node* before;
}List;

void init(List *list);
void insert_data(List* list, int num);
void Display(List* list);
int Delete_data(List* list, int num);
void my_sort_data(List* list);

int main(void)
{
	Node* list = malloc(sizeof(Node));
	init(list);
	
	int selet = 0, num = 0;

	while (selet != 4)
	{
		printf("\n1추가\n2삭제\n3출력\n4종료\n");
		scanf_s("%d", &selet);
		switch (selet)
		{
		case 1:
			printf("추가할 데이터");
			scanf_s("%d", &num);
			insert_data(list, num);
			break;

		case 2:
			printf("삭제할 데이터");
			scanf_s("%d", &num);
			Delete_data(list, num);
			Display(list);
			break;

		case 3:
			Display(list);
			break;

		case 4:
			break;
		}
	}
}

void init(List* list)
{
	list->head = NULL;
	list->cur = NULL;
	list->before = NULL;
}

void insert_data(List* list, int num)
{
	Node* new_node = malloc(sizeof(Node));
	new_node->data = num;
	new_node->link = list->head; // 헤더를 가르킴
	list->head = new_node; //다시 헤더가 새 노드를 가리킴
}

void Display(List* list)
{
	list->cur = list->head;
	if (list->cur == NULL)
	{
		printf("아무것도 없다 이기야");
	}
	else
	{
		while (list->cur->link != NULL)
		{
			printf("%d->", list->cur->data);
			list->cur = list->cur->link;
		}
		printf("%d", list->cur->data);
	}
}

int Delete_data(List *list,int num)
{
	if (list->head == NULL) 
	{
		printf("연결리스트가 없습니다.");
	}
	else
	{
		list->cur = list->head;
		while (list->cur != NULL) //탐색
		{
			if (list->cur->data == num) //데이터가 같을 경우에
			{
				if (list->cur == list->head) //삭제할 데이터가 처음에 있을때
				{
					list->head = list->head->link; //헤더 다음칸 이동
				}
				else
				{
					list->before->link = list->cur->link; //중간이나 끝에 있다면 cur 을 건너뛰고 cur 의 다음칸으로 
				}
				free(list->cur);
				return 1;
			}
			else//못찾으면 한칸식 탐색
			{
				list->before = list->cur;
				list->cur = list->cur->link;
			}
		}
	}
}

void my_sort_data(List* list)
{
	list->cur = list->head;
	list->before = list->head;
	
	if (list->cur == NULL)
	{
		
	}
}