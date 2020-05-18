#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
	struct node *prev;  // ссылка на предыдущий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
	struct node *tail;  // конец списка
} list;


// инициализация пустого списка
void init(list *l) {
 l->head = NULL;
 l->tail = NULL;
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
  l->head->next = NULL;
  l->head->prev = NULL;
  free (l->head);
}

// проверка на пустоту списка
bool is_empty(list *l) {
 node *temp = l->head;
 if (temp != NULL)
  return 1;
 }

// поиск элемента по значению. вернуть NULL если элемент не найден
node *find(list *l, int value) {
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
        temp = temp->next;
    temp->next = (struct node*)malloc(sizeof(node));
    temp->next->value = value;
    temp->next->prev = temp;
    temp->next->next = NULL;
    l->tail = temp->next;
    
   return 0;
  }
  else
  {
   node *temp = (struct node*)malloc(sizeof(node));
   temp->value = value;
   temp->next = l->head;
   l->head = temp; 
   l->head->prev = NULL; 
   l->tail = temp;
   return 0;
  };
}

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value) {
 node *temp = (struct node*)malloc(sizeof(node));
 if (!temp)
    return 1;
   temp->value = value;
   temp->next = l->head;
   temp->prev = NULL;
   l->head = temp; 
   l->head->next->prev = temp; 
   return 0;
} 

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(list *l, node *n, int value) {
 if ((n != NULL) && (n->next != NULL)) 
  {
   node *temp;
   temp = (struct node*)malloc(sizeof(node)); 
   temp->value = value; 
   temp->next = n->next;
   temp->prev = n;  
   n->next = temp; 
   n->next->next->prev = temp;
   return 0; 
  }
  else 
     {
       push_back(l, value);
       return 0;
     };
}

// вставка значения перед указанным узлом, вернуть 0 если успешно
int insert_before(list *l, node *n, int value) {
  if ((n != NULL) && (n->prev != NULL))
 { 
  node *temp;
  temp = (struct node*)malloc(sizeof(node)); 
  temp->value = value; 
  temp->prev = n->prev;
  temp->next = n;
  n->prev = temp;
  n->prev->prev->next = temp;
  return 0;
  }
    else 
    { 
       push_front(l, value);
       return 0;  
     } ;
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
int remove_first(list *l, int value) {
 if (l->head == NULL)
     return 1;
    else {
    node *temp = l->head;
    while (temp->next != NULL)
     {
      if (temp->value == value)
         {
           if (temp->prev==NULL)
              {
                l->head = temp->next;
                temp->next->prev = NULL;
                free (temp);
                return 0;
              }
            temp->prev->next = temp->next;
            temp->next->prev=temp->prev;
            free (temp); 
            return 0;
         }
        temp = temp->next;
      } 
    if (temp->value == value) {
         l->tail = temp->prev;
         temp->prev->next = NULL;
         free (temp); 
         return 0;
  } return 1;
 }
}

// удалить последний элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_last(list *l, int value) {
 if (l->head == NULL)
     return 1;
    else {
    node *temp = l->tail;
    while (temp->prev != NULL)
     {
      if (temp->value == value)
         {
           if (temp->next==NULL)
              {
                l->tail = temp->prev;
                l->tail->next = NULL;
                free (temp);
                return 0;
              }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            free (temp); 
            return 0;
         }
        temp = temp->prev;    
      }
    if (temp->value == value) {
         l->head = temp->next;
         temp->next->prev = NULL;
         free (temp); 
         return 0;
  }return 1; 
 } 
}

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l) {
  node *temp = l->head;
  while (temp != NULL) {
    printf("%d ", temp->value); 
    temp = temp->next; 
  };
 }

// вывести все значения из списка в обратном порядке через пробел,
// после окончания вывода перейти на новую строку
void print_invers(list *l) {
  node *temp = l->tail; 
  while (temp != NULL) {
    printf("%d ", temp->value); 
    temp = temp->prev; 
  };
}


int main() {
  int n, a, i, j, u;
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
 print_invers (&l);
 printf ("\n"); 
 
// добавление в начало
 (void) scanf ("%d", &a);
 push_front (&l, a);
 print (&l);
 printf ("\n"); 

// добавление после указанного узла
 (void) scanf ("%d", &j);
 (void) scanf ("%d", &a);
 node *x = find_ind (&l, j); 
 insert_after (&l, x, a);
 print_invers (&l);
 printf ("\n");

// добавление перед указанным узлом
 (void) scanf ("%d", &u);
 (void) scanf ("%d", &a);
 node *y = find_ind (&l, u); 
 insert_before (&l, y, a);
 print (&l);
 printf ("\n");

// удаление первого элемента
 (void) scanf ("%d", &a);
 remove_first (&l, a);
 print_invers (&l);
 printf ("\n");

// удаление последнего элемента
 (void) scanf ("%d", &a);
 remove_last (&l, a);
 print (&l);
 printf ("\n");

clean (&l);
	return 0;
};
