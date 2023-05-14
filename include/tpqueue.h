// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
      T data;
      Item* next;
    };
    Item* head;
    Item* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
      while (head) {
        pop();
      }
    }
    void push(const T& value) {
      Item* osn = new Item;
      osn->data = value;
      osn->next = nullptr;
      if (head == nullptr) {
        head = osn;
        tail = osn;
        return;
      }
      if (head->osn.prior < osn.prior) {
        osn->next = head;
        head = osn;
        return;
      }
      Item* dop = head;
      while (dop->next != nullptr && dop->next->data.prior >= value.prior) {
        dop = dop->next;
      }
      osn->next = dop->next;
      dop->next = osn;
      if (osn->next == nullptr) {
        tail = osn;
      }
    }
    void T pop() {
      Item* del = head->next;
      T data = head->data;
      delete head;
      head = del;
      return data;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
