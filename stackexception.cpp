#include <iostream>
using namespace std;


class Stack {
public:
    virtual void push(int var) = 0; 
    virtual int pop() = 0;          
};


class ArrayStack : public Stack {
private:
    static const int MAX = 3; 
    int st[MAX];              
    int top;                  

public:
	class overflow{
	};
	class underflow{
	};
    ArrayStack() : top(-1) {} 

    void push(int var) override {
        if (top >= MAX - 1) { 
            throw overflow(); 
        }
        st[++top] = var;
    }

    int pop() override {
        if (top < 0) { 
            throw underflow(); 
        }
        return st[top--];
    }
};

int main() {
    ArrayStack s1;
    try {
        s1.push(11);
        s1.push(22);
        s1.push(33);
        
        cout << "1: " << s1.pop() << endl;
        cout << "2: " << s1.pop() << endl;
        cout << "3: " << s1.pop() << endl;
        cout << "4: " << s1.pop() << endl; 
    } catch (ArrayStack::overflow) {
        cout << "Exception: stack full" << endl;
    } catch (ArrayStack::underflow) {
        cout << "Exception: underflow" << endl;
    }
    return 0;
}
