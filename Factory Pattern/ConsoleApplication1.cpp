// Виконав Іван Єнко
#include <Windows.h>
#include <iostream>
#include <string>

// Абстрактний клас продукту
class Product {
public:
    virtual std::string getName() const = 0;
    virtual ~Product() {}
};

// Конкретні класи продуктів
class ConcreteProductA : public Product {
public:
    std::string getName() const override {
        return "Product A";
    }
};

class ConcreteProductB : public Product {
public:
    std::string getName() const override {
        return "Product B";
    }
};

// Абстрактна фабрика
class Factory {
public:
    virtual Product* createProduct() = 0;
    virtual ~Factory() {}
};

// Конкретні фабрики
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};

// Клієнтський код
void clientCode(Factory& factory) {
    Product* product = factory.createProduct();
    std::cout << "Product: " << product->getName() << std::endl;
    delete product;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ConcreteFactoryA factoryA;
    ConcreteFactoryB factoryB;

    std::cout << "Client using factory A:" << std::endl;
    clientCode(factoryA);

    std::cout << "\nClient using factory B:" << std::endl;
    clientCode(factoryB);

    return 0;
}
