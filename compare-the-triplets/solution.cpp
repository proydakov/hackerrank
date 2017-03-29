#include <cmath>
#include <array>
#include <iostream>
#include <algorithm>

void read(std::array<int, 3>& buffer)
{
    for(int i = 0; i < 3; i++) {
        int temp;
        std::cin >> temp;
        buffer[i] = temp;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);

    std::array<int, 3> aarray;
    std::array<int, 3> barray;

    read(aarray);
    read(barray);

    int ascore = 0;
    int bscore = 0;

    for(int i = 0; i < 3; i++) {
        if(aarray[i] > barray[i]) {
            ascore++;
        }
        else if(aarray[i] < barray[i]) {
            bscore++;
        }
    }
    std::cout << ascore << " " << bscore << std::endl;

    return 0;
}
