#include <iostream>

int main()
{
    int size = 0;
    int height = 0;

    std::cin >> size;
    std::cin >> height;

    int max_height = height;

    for(int i = 0; i < size; i++) {
        int temp;
        std::cin >> temp;

        if(temp > max_height) {
            max_height = temp;
        }
    }
    std::cout << (max_height - height) << std::endl;

    return 0;
}
