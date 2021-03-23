/*
19. Тип информационного поля char*.
Добавить в список элементы с номерами 1, 3, 5 и т. д.

*/

#include <iostream>

using namespace std;

struct node
{
char data;        //информационное поле типа int
node* pointNext;  //адрес структуры следующего элемента списка
node* pointPrev;  //адрес структуры предыдущего элемента списка
};                //Нет семиколона - нет стипендии

node* make (int size)
{
  if (size == 0)
  {
    cout << "\nСписок не может быть создан!\n";
    return 0;
  }
  node* first, *point;
  first = NULL;   //Пока нет элементов, first указывает на NULL
  point = new node; //Выделяем память под под элемент
  cout << "\nВведите 1-ый элемент:\t";
  cin >> point->data;
  first = point; //first указывает на первый элемент
  point->pointNext = NULL; //т.к. это первый элемент, "слева" и "справа"
  point->pointPrev = NULL; //указываем на NULL
  for (int i = 2; i <= size; i++)
  {
    node* h = new node;   //Выделяем память под новый элемент
    node* q = point;      //Это будет указатель на предыдущий элемент, после того как мы создали новый
    point->pointNext = h; //Это будет указатель на новый элемент, следующий за предыдущим
    point = point->pointNext; //Переходим на след. элемент
    cout << "\nВведите элемент №" << i << ":\t";
    cin >> point->data; //Записали данные в новый элемент
    point->pointNext = NULL; //Проводим стрелку на NULL, т.к. элемент крайний и следующего нет
    point->pointPrev = q;    //Проводим стрелку на предыдущий элемент
  }
  return first;
}

void print(node* first)
{
  if (first == NULL)
  {
    cout << "Список пустой\n"; 
  }
  else
  {
    node* point = first;
    while (point != NULL) //Идём до последнего элемента
    {
      cout << point->data << " "; //Выводим значение элемента на котором находимся
      point = point->pointNext;   //Перемещаем указатель на след. элемент
    }
    cout << endl;
  }
}

void add_1_3_5(node* &first, int size)
{
  node* point = first;
  int add_element = size, No = 1;
  char arr[add_element];
  for (int i = 0; i < add_element; i++)
  {
    cout << "\nВведите добавляемый элемент №" << No << ":\t";
    cin >> arr[i]; 
    No+=2;
  }
  node* h = new node;
  h->data = arr[0];
  h->pointNext = first;
  first->pointPrev = h;
  h->pointPrev = NULL;
  first = h;

  for (int i = 1; i < add_element; i++)
  {
    node* h = new node;
    h->data = arr[i];
    h->pointNext = point->pointNext;
    h->pointPrev = point;
    point->pointNext->pointPrev = h;
    point->pointNext = h;

    point=point->pointNext;
    point=point->pointNext;
  }
}

int main()
{
  setlocale (LC_ALL, "ru");
  int size;
  cout << "Введите размер списка:\t";
  while (size < 1) 
  {
    cin >> size;
  }

  node* node = make(size);
  cout << "\nВаш список:\n";
  print(node);

  add_1_3_5(node, size);

  cout << "\nСписок после добавления:\n";
  print(node);

  return 0;
}
