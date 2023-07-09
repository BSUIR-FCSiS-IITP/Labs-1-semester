#include <iostream>
#include <string>
#include <regex>
#include <vector>


void process_string(const std::string &src1) {
    std::string src = src1;
    std::vector<double> a ;
    std::smatch res;
    std::regex reg("([0-9]*[.])?[0-9]+");
    while (regex_search(src, res, reg)) {
        a.push_back(std::stod(res.str())) ;
        src = res.suffix();
    }
    long long max = 0 ;
    for (int i : a) {
        auto b = (long long) a[i] ;
        if (b > max)
            max = b ;
    }
    std::cout << max ;
}

int main() {
    std::string s, s1 ;
    getline(std::cin, s) ;
    process_string(s);
}