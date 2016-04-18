#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/// Очередь
/// =======

struct Queue {

};

/// Стек
/// ====


int main() {
  // Очередь
  queue<int> q1;
  // Добавляем новый элемент
  // push_queue(q1, 1) - если без классов
  q1.push(1);
  q1.push(2);
  cout << "q1.size() = " << q1.size() << endl;
  // Последний элемент
  cout << "1 - " << q1.front() << endl;
  q1.pop();
  cout << "2 - " << q1.front() << endl;
  q1.pop();

  // Работа со стандартным стеком
  stack<int> s1;
  s1.push(1);
  s1.push(2);
  s1.push(3);
  cout << "s1.size() = " << s1.size() << endl;
  cout << "s1.top() = " << s1.top() << endl;
  s1.pop();
  cout << "s1.top() = " << s1.top() << endl;
  s1.pop();
  cout << "s1.empty() = " << s1.empty() << endl;
  cout << "s1.top() = " << s1.top() << endl;
  s1.pop();
  // Стек пуст
  cout << "s1.empty() = " << s1.empty() << endl;


  return 0;
}