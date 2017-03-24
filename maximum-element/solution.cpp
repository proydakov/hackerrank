#include <stack>
#include <iostream>

template<class T>
class max_stack
{
public:
    void push(T val)
    {
        vals.push(val);
        if(!maxs.empty()) {
            if(val >= maxs.top()) {
                maxs.push(val);
            }
        }
        else {
            maxs.push(val);
        }
    }

    void pop()
    {
        if(!vals.empty()) {
            T top = vals.top();
            vals.pop();
            if(top == maxs.top()) {
                maxs.pop();
            }
        }
    }

    T top()
    {
        return vals.top();
    }
    
    T max_top()
    {
        return maxs.top();
    }
    
private:
    std::stack<T> vals;
    std::stack<T> maxs;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::size_t size = 0;
    std::cin >> size;

    max_stack<int> stack;

    for(size_t i = 0; i < size; i++) {
        int operation;
        int val;
        
        std::cin >> operation;
        switch(operation) {
            case 1:
            {
                std::cin >> val;
                stack.push(val);
            }
            break;
            
            case 2:
            {
                stack.pop();
            }
            break;
            
            case 3:
            {
                int max = stack.max_top();
                std::cout << max << std::endl;
            }
            break;
        }
    }

    return 0;
}
