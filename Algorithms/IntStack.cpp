#include "IntStack.h"
#include <cassert>

void IntStack::push(int value) {
    topElement = new Element(value, topElement ? topElement : nullptr);
}

int IntStack::pop() {
    assert(topElement);

    Element* poppedElement = topElement;
    int result = poppedElement->value;

    topElement = poppedElement->previous;

    delete poppedElement;
    return result;
}

bool IntStack::isEmpty() {
    return !topElement;
}