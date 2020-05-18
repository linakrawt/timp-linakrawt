#include <stdio.h>
#include <stdlib.h>


// Структура для хранения узла дерева
// Необходимо хранить ссылки на потомков, предка и некоторое значение
typedef struct node {
    int value;          // значение, которое хранит узел
    struct node* left;  // ссылка на левого потомка
    struct node* right;  // ссылка на правого потомка
    struct node* parent;  // ссылка на предка
} node;


// Структура для хранения дерева.
// Хранит ссылку на корень дерева и количество элементов в дереве
typedef struct tree {
    struct node* root;  // корень
    int qt; // количество элементов
} tree;


// Инициализация дерева
void init(tree* t) {
    t->root = NULL;
    t->qt = 0;
}

int insert(tree* t, int value) {
    node *prev = t->root, *next = NULL;
    node *temp = malloc(sizeof(node));
    temp->value = value;
    if (t->root == NULL) {
        temp->parent = NULL;
        temp->left = NULL;
        temp->right = NULL;
        t->root = temp;
        t->qt = 1;
        return 0;
    }
    while (prev != NULL) {
        next = prev;
        if (value == prev->value) {
            return 1;
        }
        if (value < prev->value) {
            prev = prev->left;
        }
        else {
        prev = prev->right;
        }
    }
    temp->parent = next;
    temp->left = NULL;
    temp->right = NULL;
    if (value < next->value) {
        next->left = temp;
        t->qt++;
        return 0;
    }
    if (value > next->value) {
        next->right = temp;
        t->qt++;
        return 0;
    }
}

//Функция, возвращающая указатель на корень
node* getRoot(tree* t)
{
    return t->root;
}

typedef struct struct_item {
    void* payload;
    struct struct_item* next;
} item;

typedef struct struct_queue {
    item* begin;
    item* end;
}queue;

queue* create_queue() {
    queue* res = malloc(sizeof(queue));
    res->begin = NULL;
    res->end = NULL;
    return res;
}

void queue_push(queue* q, void* payload) {
    item* i = malloc(sizeof(item));
    i->next = NULL;
    i->payload = payload;

    if (q->end == NULL) {
        q->begin = i;
        q->end = i;
    }
    else {
        q->end->next = i;
        q->end = i;
    }
}

void* queue_pop(queue* q) {
    if (q->begin == NULL) return NULL;
    item* current = q->begin;
    q->begin = q->begin->next;
    if (q->begin == NULL) q->end = NULL;
    void* payload = current->payload;
    free(current);
    return payload;
}

void breadthFirst (node* root) {
  queue* q_current = NULL;
  queue* q_next = create_queue();
  queue_push(q_next, (void*)root);
  int isNotLastLevel;
  do {
      free(q_current);
      q_current = q_next;
      q_next = create_queue();
      void* payload;
      isNotLastLevel = 0;
      while (q_current->begin != NULL) {
          payload = queue_pop(q_current);
          if (payload != NULL) {
              node* n = (node*)payload;
              printf("%d ", n->value);
              queue_push(q_next, n->left);
              queue_push(q_next, n->right);
              isNotLastLevel = isNotLastLevel || n->left || n->right;
          }
          else {
              queue_push(q_next, NULL);
              queue_push(q_next, NULL);
          }
      }
  } while (isNotLastLevel);
}

int main() {
    int n, a;
    tree t;
    init(&t);
    for (int i=0; i < 7; ++i)
    {
        (void) scanf("%d", &a);
        insert(&t, a);
    }

 // ОБХОД В ШИРИНУ
 breadthFirst (getRoot(&t));
 printf("\n");

return 0;

};
