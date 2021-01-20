// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class Type>
class MyStack {
 private:
  int size;
  int head;
  Type* stack;

 public:
  explicit MyStack(int n) {
    size = n;
    head = 0;
    stack = new Type[n];
  }

  MyStack(const MyStack &st) {
    size = st.size;
    head = st.head;
    stack = new Type[size];
    for (int i = 0; i < head; i++) {
      stack[i] = st.stack[i];
    }
  }

  ~MyStack() {
    delete[] stack;
    size = 0;
    head = 0;
  }

  Type get() const {
    return stack[head - 1];
  }

  Type pop() {
    if (isEmpty()) {
      throw "Stack is empty!";
    } else {
      head--;
      return stack[head];
    }
  }

  void push(Type element) {
    if (head >= size)
      return;
    stack[head] = element;
    head++;
  }

  bool isFull() const {
    return head == size;
  }

  bool isEmpty() const {
    return head == 0;
  }
};
#endif  //  INCLUDE_MYSTACK_H_
