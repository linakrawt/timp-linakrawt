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


void postOrder (node* t) {

  if (t== NULL)
  return;
postOrder(t->left);
postOrder(t->right);
printf("%d ", t->value);
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

 // ОБРАТНЫЙ ОБХОД
 postOrder (getRoot(&t));

  return 0;


};
