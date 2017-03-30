#include <set>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

struct point
{
    int x;
    int y;
};

struct compare
{
    compare(int width) : width_(width) {}

    bool operator() (const point& lhs, const point& rhs) const{
        return lhs.y * width_ + lhs.x < rhs.y * width_ + rhs.x;
    }

private:
    int width_;
};

class matrix
{
public:
    matrix() : n_(0), m_(0), group_index_(2) {}

    void read()
    {
        std::cin >> n_;
        std::cin >> m_;

        data_.reserve(n_ * m_);
        data_.resize(0);

        for(int i = 0; i < n_ * m_; i++) {
            int temp;
            std::cin >> temp;
            data_.push_back(temp);
        }
    }

    int& at(int x, int y)
    {
        return data_[y * width() + x];
    }

    int at(int x, int y) const
    {
        return data_[y * width() + x];
    }

    int search_and_mark(int x, int y)
    {
        point p{x, y};
        at(x, y) = group_index_;

        int counter = 0;

        compare cmp(width());
        std::set<point, compare> set(cmp);
        set.insert(p);

        std::vector<point> result;
        result.reserve(8);

        while(!set.empty()) {
            auto it = set.begin();

            const int px = it->x;
            const int py = it->y;

            at(px, py) = group_index_;
            counter++;

            get_neighbors(px, py, result);

            set.erase(it);

            for(const auto pt : result) {
                if(is_markable(pt.x, pt.y)) {
                    set.insert(pt);
                }
            }
        }

        group_index_++;

        return counter;
    }

    int height() const
    {
        return n_;
    }

    int width() const
    {
        return m_;
    }

    void get_neighbors(int x, int y, std::vector<point>& result) const
    {
        result.resize(0);

        const int ybegin = std::max(0, y - 1);
        const int ym = std::min(height() - 1, y + 1);

        const int xbegin = std::max(0, x - 1);
        const int xm = std::min(width() - 1, x + 1);

        for(int yi = ybegin; yi <= ym; yi++) {
            for(int xi = xbegin; xi <= xm; xi++) {
                if(xi == x && yi == y) {
                    continue;
                }

                result.push_back(point{xi, yi});
            }
        }
    }

    bool is_markable(int x, int y) const
    {
        return at(x, y) == 1;
    }

private:
    std::vector<int> data_;

    int n_;
    int m_;

    int group_index_;
};

std::ostream& operator<<(std::ostream& os, const matrix& m)
{
    const int height = m.height();
    const int width  = m.width();
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            os << m.at(x, y) << " ";
        }
        os << "\n";
    }
    return os;
}

void solve()
{
    matrix m;
    m.read();

    int max = 0;

    const int height = m.height();
    const int width  = m.width();

    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            if(!m.is_markable(x, y)) {
                continue;
            }
            const int test_score = m.search_and_mark(x, y);
            if(test_score > max) {
                max = test_score;
            }
        }
    }

    std::cout << max << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}
