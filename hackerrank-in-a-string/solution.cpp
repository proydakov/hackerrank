#include <string>
#include <iostream>
#include <algorithm>

class machine
{
public:
    machine(const std::string& str) : str_(str) {}

    bool process(const std::string& text) const
    {
        size_t index = 0;

        const size_t search_size = str_.size();

        const size_t size = text.size();
        for(size_t i = 0; i < size; i++) {
            if(text[i] == str_[index]) {
                index++;
            }
            if(search_size == index) {
                return true;
            }
        }
        return false;
    }

private:
    std::string str_;
};

void solve()
{
    std::string str;
    std::cin >> str;

    machine m("hackerrank");
    const bool res = m.process(str);

    if(res) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++) {
        solve();
    }

    return 0;
}
