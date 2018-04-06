#include <stdio.h>
#define MAXN 100
typedef struct node {
    int v;
    struct node * next;
} Node;
typedef struct {
    Node * head;
    Node * rear;
} Queue;
   
int n[MAXN];
int a[MAXN][MAXN];

int main(void) {
    int n, m, i, j, index, x, t;
    int max = 1, h = 0, maxh = 1, count = 1;
    Queue q;
    
    initialize(&q);
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &index);
        scanf("%d", &n[index]);
        for (j = 0; j < n[index]; j++)
            scanf("%d", &a[index][j]);
    }
    
    enqueue(1, &q);
    while (!isEmpty(&q)) {
        h++;
        if (max < count) {
            max = count;
            maxh = h;
        }
        t = 0;
        for (i = 0; i < count; i++) {
            x = dequeue(&q);
            for (j = 0; j < n[x]; j++) {
                enqueue(a[x][j], &q);
            }
            t += n[x];
        }
        count = t;
    }
    
    return 0;
}

void initialize(Queue * pq) {
    pq->head = NULL;
    pq->rear = null;
    return;
}

int isEmpty(Queue * pq) {
    if (pq->head == null)    return 1;
    else                     return 0;
}

void enqueue(int v, Queue * pq) {
    Node * old_rear = pq->rear;
    Node * new_node = (Node *) malloc(sizeof(Node));
    
    new_node->v = v;
    new_node->next = null;
    pq->rear = new_node;
    if (pq->head == null)   pq->head = pq->rear;
    else                    old_rear->next = pq->rear;
    return;
}

int dequeue(Queue * pq) {
    if (isEmpty(pq))    return;
    int temp = pq->head->v;
    
    pq->head = pq->head->next;
    if (pq->head == null)   pq->rear = null;
    
    return temp
}
