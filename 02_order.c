#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

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


typedef struct stack{
        int top;
        node *items[STACK_SIZE];
}stack;

void push(stack *ms, node *item){
   if(ms->top < STACK_SIZE-1){
       ms->items[++(ms->top)] = item;
   }
   else {
       printf("Stack is full\n");
   }
}

node * pop (stack *ms){
   if(ms->top > -1 ){
       return ms->items[(ms->top)--];
   }
   else{
       printf("Stack is empty\n");
   }
}
node * peek(stack ms){
  if(ms.top < 0){
      printf("Stack empty\n");
      return 0;
   }
   return ms.items[ms.top];
}
int isEmpty(stack ms){
   if(ms.top < 0) return 1;
   else return 0;
}


void preOrder (node* t) {
  stack ms;
    ms.top = -1;

    if(t == NULL) return ;

    node *temp = NULL;
    push(&ms,t);

    while(!isEmpty(ms)){
        temp = pop(&ms);
        printf("%d ", temp->value);
        if(temp->right){
            push(&ms, temp->right);
        }
        if(temp->left){
            push(&ms, temp->left);
        }
    }
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

 // ПРЯМОЙ ОБХОД
preOrder (getRoot(&t));
printf("\n");


  return 0;


};
