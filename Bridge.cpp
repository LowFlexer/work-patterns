#include <iostream>

// Абстракція
class Abstraction {
public:
    virtual void operation() const = 0;
    virtual ~Abstraction() {}
};

// Реалізація
class Implementation {
public:
    virtual void performOperation() const = 0;
    virtual ~Implementation() {}
};

// Конкретна реалізація 1
class ConcreteImplementation1 : public Implementation {
public:
    void performOperation() const override {
        std::cout << "Concrete Implementation 1" << std::endl;
    }
};

// Конкретна реалізація 2
class ConcreteImplementation2 : public Implementation {
public:
    void performOperation() const override {
        std::cout << "Concrete Implementation 2" << std::endl;
    }
};

// Конкретна абстракція
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementation* implementation) : implementation_(implementation) {}

    void operation() const override {
        implementation_->performOperation();
    }

private:
    Implementation* implementation_;
};

int main() {
    // Створення об'єктів реалізації
    ConcreteImplementation1 implementation1;
    ConcreteImplementation2 implementation2;

    // Створення об'єктів абстракції та пов'язання їх з реалізацією
    RefinedAbstraction abstraction1(&implementation1);
    RefinedAbstraction abstraction2(&implementation2);

    // Виклик методу абстракції, який використовує реалізацію
    abstraction1.operation();
    abstraction2.operation();

    return 0;
}
