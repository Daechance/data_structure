#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct  Node* prev;
	struct Node* next;
}Node;

typedef struct list {
	Node* head;
	Node* cur;
}List;

void Init(List* list);
void insert(List *list,int data);
void Display(List* list);
void Delete(List* list, int data);

int main(void)
{
	List list;
	int select = 0;
	int data=0;
	Init(&list);

	while (select != 4)
	{
		printf("\n1)추가\n2)삭제\n3)출력\n4)종료\n--------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1: 
			printf("값 입력 :");
			scanf("%d", &data);
			insert(&list, data);
			Display(&list);
			break;
		case 2:
			printf("삭제 값 입력 :");
			scanf("%d", &data);
			Delete(&list, data);
			Display(&list);
			break;
		case 3:
			Display(&list);
			break;
		case 4:
			break;
		}
	}
}

void Init(List* list)
{
	list->head = NULL;
	list->cur = NULL;
}

void insert(List* list, int data)
{
	Node* new_node = malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL; //첫값 초기와
	new_node->prev = NULL;

	if (list->head == NULL)
	{
		list->head = new_node; //비어 있을경우는 헤드는 새노드를 가르킨다
	}
	else //그렇지 않을 경우
	{
		new_node->next = list->head; //새노드의 링크는 헤드를 가르키고 
		list->head->prev = new_node; //prev는 바로 새노드 가르킴
		list->head = new_node; //헤드는 다시 새노드를 가르킨다
	}
}

void Display(List* list)
{
	if (list->head == NULL)
	{
		printf("Dont have linked list");
		return 0;
	}
	else
	{
		list->cur = list->head;
		
		printf("next \n");
		while (list->cur->next != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->next;
		}
		printf("%d ",list->cur->data);

		printf("\nprev \n");
		while (list->cur->prev != NULL)
		{
			printf("%d ->", list->cur->data);
			list->cur = list->cur->prev;
		}
		printf("%d ", list->cur->data);

	}
}

void Delete(List* list,int data)
{


	if (list->head == NULL) //비었을경우
	{
		printf("Dont have linked list");
		return 1;
	}
	else //데이터가 있을경우
	{
		while (list->cur != NULL)
		{
			if (list->cur->data == data) //값찾을 경우에
			{
				if (list->cur == list->head) //만약 처음부터 같다면
				{
					list->head = list->head->next; //헤더는 다음 값을 가지도록
					list->head->prev = NULL; //이전 값은 없으니 NULL
				}
				else if (list->cur->next == NULL) // 다음이 없을경우
				{
					list->cur->prev->next = NULL;//커렌트 가진 값전 값에 다음은 없으니까 NULL
				}
				else
				{
					list->cur->prev->next = list->cur->next; //커렌트 이전값에 다음 노드는 커랜트의 다음값으로
					list->cur->next->prev = list->cur->prev; // 커렌트 다음값에 이전 노드는 커랜트의 이전값으로
				}
				free(list->cur);
				return 1;
			}
			else //없을경우
			{
				list->cur = list->cur->next;
			}
		}
		printf("삭제할 값이 없습니다.");
		return 0;
	}
}