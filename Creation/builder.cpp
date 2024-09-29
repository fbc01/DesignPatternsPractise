#include <iostream>
using namespace std;

class Product {
private:
    int id;
    string name;
    int price;

public:
    void setId (int x) {
        id = x;
    }
    void setName (string s) {
        name = s;
    }
    void setPrice (int p) {
        price = p;
    }
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    int getPrice() {
        return price;
    }
};

class BuilderInterface {
public:
    virtual void buildId(int x) = 0;
    virtual void buildName(string s) = 0;
    virtual void buildPrice(int p) = 0;
    virtual Product* build() = 0;
};

class ConcreteBuilder: public BuilderInterface {
private:
    Product* product;

public:
    ConcreteBuilder() {
        product = new Product();
    }

    void buildId(int x) override {
        product->setId(x);
    }

    void buildName(string s) override {
        product->setName(s);
    }

    void buildPrice(int p) override {
        product->setPrice(p);
    }

    Product* build() override {
        return product;
    }
};

class Director {
public:
    void construct(BuilderInterface* builder) {
        builder->buildId(1);
        builder->buildName("hello");
        builder->buildPrice(100);
    }
};

void Client() {
    ConcreteBuilder* builder = new ConcreteBuilder();
    Director* director = new Director();
    director->construct(builder);
    Product* product = builder->build();
    cout << product->getId() << " " << product->getName() << " " << product->getPrice() << endl;
}

int main() {
    Client();

    return 0;
}