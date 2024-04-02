#include <iostream>
#include <queue>

template <typename T>
class PriorityQueue {
private:
    std::priority_queue<T> pq;

public:
    PriorityQueue() {}

    PriorityQueue(const T& val) {
        pq.push(val);
    }

    PriorityQueue(const PriorityQueue& other) {
        pq = other.pq;
    }

    void push_back(const T& val) {
        pq.push(val);
    }

    void pop() {
        pq.pop();
    }

    T top() const {
        return pq.top();
    }

    T back() const {
        std::priority_queue<T> tmp = pq;
        while (tmp.size() > 1) {
            tmp.pop();
        }
        return tmp.top();
    }

    bool empty() const {
        return pq.empty();
    }

    size_t size() const {
        return pq.size();
    }

    bool operator<(const PriorityQueue& other) const {
        return pq < other.pq;
    }

    bool operator>(const PriorityQueue& other) const {
        return pq > other.pq;
    }
};

int main() {
    PriorityQueue<int> pq;
    pq.push_back(3);
    pq.push_back(7);
    pq.push_back(1);

    std::cout << "Top element: " << pq.top() << std::endl;
    std::cout << "Back element: " << pq.back() << std::endl;
    std::cout << "Size of queue: " << pq.size() << std::endl;

    pq.pop();
    std::cout << "After pop, top element: " << pq.top() << std::endl;

    PriorityQueue<int> pq2(pq);
    std::cout << "Copied queue size: " << pq2.size() << std::endl;

    PriorityQueue<int> pq3(10);
    std::cout << "Queue with single value, top element: " << pq3.top() << std::endl;

    return 0;
}
