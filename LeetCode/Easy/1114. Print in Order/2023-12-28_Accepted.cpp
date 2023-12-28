class Foo {
private:
  bool isFirstExecuted;
  bool isSecondExecuted;

public:
  Foo() {
    isFirstExecuted = false;
    isSecondExecuted = false;
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    isFirstExecuted = true;
  }

  void second(function<void()> printSecond) {
    while (!isFirstExecuted) {
      this_thread::sleep_for(chrono::milliseconds(1));
    }

    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    isSecondExecuted = true;
  }

  void third(function<void()> printThird) {
    while (!isSecondExecuted) {
      this_thread::sleep_for(chrono::milliseconds(1));
    }

    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
