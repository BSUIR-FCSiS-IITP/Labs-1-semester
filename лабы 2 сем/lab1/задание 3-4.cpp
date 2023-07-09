#include <iostream>

class Expression
{
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};

class Number : public Expression
{
public:
    explicit Number(double value) : value(value)
    {}

    double evaluate() const override {
        return this->value;
    }

    ~Number() override = default;

private:
    double value;
};

class BinaryOperation : public Expression
{
public:
    BinaryOperation(Expression const * left, char op, Expression const * right): left(left), op(op), right(right)
    {}

    double evaluate() const override {
        switch (this->op) {
            case '+':
                return this->left->evaluate() + this->right->evaluate();
            case '-':
                return this->left->evaluate() - this->right->evaluate();
            case '*':
                return this->left->evaluate() * this->right->evaluate();
            case '/':
                return this->left->evaluate() / this->right->evaluate();
            default:
                break;
        }
    }

    ~BinaryOperation() override {
        delete this->left;
        delete this->right;
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{

    return ((void(*(*(&)[2]))(const Expression&))left)[0][0] == ((void(*(*(&)[2]))(const Expression&))right)[0][0];
}

bool check_equals1(Expression const *left, Expression const *right) {
    int* new1 =  *(int**)left;
    int* new2 =  *(int**)right;
    return (new1 == new2);
}



int main() {
    Expression *sube = new BinaryOperation(new BinaryOperation(new Number(4.5), '*', new Number(5)), '+', new BinaryOperation(new Number(4.5), '*', new Number(5)));
    Expression *expr = new BinaryOperation(new Number(3), '+', sube);
    std::cout << sube -> evaluate() << '\n';
    delete expr;
    Expression *new1 = new BinaryOperation(new Number(1), '+', new Number(5));
    Expression *new2 = new BinaryOperation(new Number(2), '+', new Number(5));
    std::cout << std::boolalpha << check_equals(new1, new2);
}