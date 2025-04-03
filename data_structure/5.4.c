#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ==== ���� ��(Deque) ====
#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �� �ʱ�ȭ �Լ�
void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� ť ��� �Լ�
void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % MAX_QUEUE_SIZE;
			printf("%d |", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

// �Ĺ� ���� �Լ�
void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("���� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ���� ���� �Լ�
element delete_front(DequeType* q) {
	if (is_empty(q)) {
		error("���� ��������Դϴ�.");
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

// ���� ��ȸ �Լ�
element get_front(DequeType* q) {
	if (is_empty(q))
		error("���� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ���� ���� �Լ�
void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("���� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// �Ĺ� ���� �Լ�
element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("���� ��������Դϴ�.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

// �Ĺ� ��ȸ �Լ�
element get_rear(DequeType* q) {
	if (is_empty(q))
		error("���� ��������Դϴ�.");
	return q->data[q->rear];
}


int main(void) {
	DequeType deque;

	init_deque(&deque);
	printf("-- Front���� ������ �߰� --\n");
	for (int i = 0; i <= 3; i++) {
		add_front(&deque, i);
		deque_print(&deque);
	}

	printf("\n-- Rear���� ������ ���� --\n");
	for (int i = 0; i < 3; i++) {
		delete_rear(&deque);
		deque_print(&deque);
	}

	return 0;
}