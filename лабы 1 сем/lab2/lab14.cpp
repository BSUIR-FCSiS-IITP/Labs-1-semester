#include <iostream>

int main() {
    long long W, H, x1, y1, x2, y2, w, h;
    std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h ;
    if (x2 - x1 == 0 || y2 - y1 == 0) {
        std::cout << -1 ;
        exit(0) ;
    }
    if (((w <= x1) && (h <= H)) || ((w <= W - x2) && (h <= H)) || ((h <= y1) && (w <= W)) || ((h <= (H - y2) && (w <= W)))) {
        std::cout << "0" ;
        exit(0) ;
    }
    else if ((x2 + (w - x1) <= W) && (h <= H))
    std::cout << w-x1 ;
    else if (((x1 - (x2 - W + w)) >= 0) && (h <= H))
    std::cout << x2-W+w ;
    else if (((y1 - y2 + H - h) >= 0) && (w <= W))
    std::cout << h - y1 ;
    else if ((y2 + (h - y1) <= H) && (w <= W))
    std::cout << y2-H+h ;
    else std::cout << "-1" ;
}