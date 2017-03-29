#include <string>
#include <iostream>

std::string wrap(int v)
{
    std::string str = std::to_string(v);
    if(str.size() == 1) {
        str = "0" + str;
    }
    return str;
}

int main()
{
    int h = 0;
    std::cin >> h;

    char c1 = ' ';
    std::cin >> c1;

    int m = 0;
    std::cin >> m;

    char c2 = ' ';
    std::cin >> c2;

    int s = 0;
    std::cin >> s;

    char K1 = 0;
    char K2 = 0;
    std::cin >> K1;
    std::cin >> K2;

    if('P' == K1 && h < 12) {
        h += 12;
    }
    else if('A' == K1 && h >= 12) {
        h -= 12;
    }
    std::cout << wrap(h) << ':' << wrap(m) << ':' << wrap(s) << std::endl;

    return 0;
}
