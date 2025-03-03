#include <iostream>
#include <vector>

typedef std::vector<std::pair<std::string, int>> pairs_t;

typedef std::string text_t;
// equalent to below:
using text_t=std::string;

int main() {
    pairs_t pairs={{"a", 1}, {"b", 2}};
    text_t fmsg="First key: ";
    text_t emsg =", First value: ";

    std::cout << fmsg << pairs[1].first << emsg << pairs[1].second << '\n';
    // std::cout<<pairs<<'\n';

    return 0;
}