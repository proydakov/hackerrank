#include <vector>
#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;

    std::vector<int> scores;
    scores.reserve(count);

    for(int i = 0; i < count; i++) {
        int temp;
        std::cin >> temp;
        scores.push_back(temp);
    }

    int min_score = scores[0];
    int max_score = scores[0];

    int min_change = 0;
    int max_change = 0;

    for(int i = 1; i < count; i++) {
        const int score = scores[i];
        if(score > max_score) {
            max_score = score;
            ++max_change;
        }
        else if(score < min_score) {
            min_score = score;
            ++min_change;
        }
    }

    std::cout << max_change << " " << min_change << std::endl;

    return 0;
}
