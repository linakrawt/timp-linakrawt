#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
} list;


// инициализация пустого списка
void init(list *l) {
 l->head = NULL;
}


// удалить все элементы из списка
void clean(list *l) {
 node *temp = NULL;
 while (l->head->next)
  {
    temp = l->head;
    l->head = l->head->next;
    free (temp);
  }
  free (l->head);
}


// проверка на пустоту списка
bool is_empty(list *l) {
 if (l->head)
     return 1;
        else return 0;
}

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value) 
 {
  node *temp = l->head;
  while ((temp !=NULL)&&(temp->value != value))
       temp = temp->next;
  return temp;
 }

// проверка поиска элемента
void check(list *l, int value) {
 if (find(l,value) != NULL)
     printf ("1 ");
     else 
         printf ("0 ");
}

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value) {
 if (l->head != NULL)
  {
   node *temp = l->head;
   while (temp->next != NULL)
      {temp = temp->next;}
   temp->next = (struct node*)malloc(sizeof(node));
   temp->next->value = value;
   temp->next->next = NULL;
   return 0;
  }
  else
  {
   node *temp = (struct node*)malloc(sizeof(node));
   temp->value = value;
   temp->next = l->head;
   l->head = temp;
   return 0;
  }
}
 

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value) {
 node *temp = (struct node*)malloc(sizeof(node));
 if (!temp)
    return 1;
 temp->value = value;
 temp->next = l->head;
 l->head = temp;
 return 0;
}


// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value) {
 node *temp = (struct node*)malloc(sizeof(node));
 temp->value = value;
 temp->next = n->next;
 n->next = temp;
 return 0;
}

// поиск элемента по индексу. вернуть NULL если эжемент не найден
node *find_ind(list *l, int j) 
 {
  node *temp = l->head;
  int i = 0;
  while ((temp != NULL)&&( i != j-1)) {
       temp = temp->next;
       ++i;
       }
  return temp;
 }

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value) {
 if (l->head == NULL)
     return 1;
    else {
    node *temp = l->head;
    node *lst = NULL; 
    while (temp->next != NULL)
     {
      if (temp->value == value)
         {
           if (lst==NULL)
              {
                l->head = temp -> next;
                free (temp);
                return 0;
              }
            lst->next = temp->next;
            free (temp); 
            return 0;
         }
        lst = temp;
        temp = temp->next;
      } return 1; 
  }
}
    

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l) {
  node *temp = l->head;
  while (temp != NULL) {
    printf("%d ", temp->value); 
    temp = temp->next; 
  } ;
 }


int main() {
 int n, a, i, j;
 (void) scanf ("%d", &n);
 list l; 
 init (&l);
 for (i=1; i<=n; ++i)
  {
   (void) scanf ("%d", &a);
   push_back (&l, a);
  }
 print (&l);
 printf ("\n");
 
// поиск элементов
 for (i=1; i<=3; ++i)
  {
   (void) scanf ("%d", &a);
   check (&l, a);
  }
 printf ("\n");

// добавление в конец
 (void) scanf ("%d", &a);
 push_back (&l, a);
 print (&l);
 printf ("\n");  

// добавление в начало
 (void) scanf ("%d", &a);
 push_front (&l, a);
 print (&l);
 printf ("\n"); 

// добавление после указанного элемента
 (void) scanf ("%d", &a);
 (void) scanf ("%d", &j);
 node *x = find_ind (&l, a);
 insert_after (x, j);
 print (&l);
 printf ("\n");

// удаление элемента
 (void) scanf ("%d", &a);
 remove_node (&l, a);
 print (&l);
 printf ("\n");
 return 0;

// очистка списка
 clean (&l);

// проверка на пустоту
bool b =  is_empty (&l);
printf ("%d ", b);
 return 0;
}

 
   

