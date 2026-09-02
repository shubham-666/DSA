class Foo {
private:
    mutex mtx;
    condition_variable cv;
    int step = 1;

public:
    Foo() {}

    void first(function<void()> printFirst) {
        printFirst();

        {
            lock_guard<mutex> lock(mtx);
            step = 2;
        }
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return step == 2;
        });

        printSecond();

        step = 3;
        lock.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, [this]() {
            return step == 3;
        });

        printThird();
    }
};