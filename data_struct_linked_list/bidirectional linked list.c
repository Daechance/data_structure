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
		printf("\n1)�߰�\n2)����\n3)���\n4)����\n--------------------------------\n");
		scanf("%d", &select);

		switch (select)
		{
		case 1: 
			printf("�� �Է� :");
			scanf("%d", &data);
			insert(&list, data);
			Display(&list);
			break;
		case 2:
			printf("���� �� �Է� :");
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
	new_node->next = NULL; //ù�� �ʱ��
	new_node->prev = NULL;

	if (list->head == NULL)
	{
		list->head = new_node; //��� �������� ���� ����带 ����Ų��
	}
	else //�׷��� ���� ���
	{
		new_node->next = list->head; //������� ��ũ�� ��带 ����Ű�� 
		list->head->prev = new_node; //prev�� �ٷ� ����� ����Ŵ
		list->head = new_node; //���� �ٽ� ����带 ����Ų��
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


	if (list->head == NULL) //��������
	{
		printf("Dont have linked list");
		return 1;
	}
	else //�����Ͱ� �������
	{
		while (list->cur != NULL)
		{
			if (list->cur->data == data) //��ã�� ��쿡
			{
				if (list->cur == list->head) //���� ó������ ���ٸ�
				{
					list->head = list->head->next; //����� ���� ���� ��������
					list->head->prev = NULL; //���� ���� ������ NULL
				}
				else if (list->cur->next == NULL) // ������ �������
				{
					list->cur->prev->next = NULL;//Ŀ��Ʈ ���� ���� ���� ������ �����ϱ� NULL
				}
				else
				{
					list->cur->prev->next = list->cur->next; //Ŀ��Ʈ �������� ���� ���� Ŀ��Ʈ�� ����������
					list->cur->next->prev = list->cur->prev; // Ŀ��Ʈ �������� ���� ���� Ŀ��Ʈ�� ����������
				}
				free(list->cur);
				return 1;
			}
			else //�������
			{
				list->cur = list->cur->next;
			}
		}
		printf("������ ���� �����ϴ�.");
		return 0;
	}
}