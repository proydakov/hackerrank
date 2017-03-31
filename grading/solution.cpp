#include <iostream>

int round(int val)
{
    if(val <= 37) {
        return val;
    }

    int del = val / 5;
    int temp = (del + 1) * 5;
    int ost = val % 5;

    if(ost != 0 && (temp - val) < 3) {
        val = temp;
    }

    return val;
}

int main()
{
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        std::cout << round(temp) << "\n";
    }

    return 0;
}
