#include<iostream>
// custom namespace used to avoid name collisions 
namespace Geometry{
    struct Point{
        int x, y;
        Point(int x, int y) : x(x), y(y){}
    };
    void printPoint(const Point &p){
        std::cout << "Point Coordinates: (" << p.x << ", " << p.y << ")" << std::endl;
    }
}

namespace G = Geometry;
int main(){
    G::Point p(3, 4);
    G::printPoint(p);
}