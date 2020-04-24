#ifndef ALGORITHMS_INTSTACK_H
#define ALGORITHMS_INTSTACK_H


class IntStack {
public:
    ~IntStack() {
        while (!isEmpty())
            pop();
    }
    void push(int value);
    int pop();
    bool isEmpty();

private:
    struct Element {
        Element(int value, Element* previous): value(value), previous(previous) {};
        int value;
        Element* previous;
    };

    Element* topElement = nullptr;
};


#endif //ALGORITHMS_INTSTACK_H
