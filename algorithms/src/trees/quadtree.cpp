#include <iostream>
#include <vector>
#include <limits>
// Credits: lisyarus blog

struct point{
    float x, y;

    
};

// define some operations with point
point middle(point const &p1, point const &p2){
    return {(p1.x + p2.x)/2.f, (p1.y + p2.y)/2.f };
}


static constexpr float inf = std::numeric_limits<float>::infinity();

struct box{
    // initialize with largest bounding box
    point min {-inf, -inf};
    point max{inf, inf};
    
    // define union of two boxes to bound the point p outside the box
    // returns a new bounding box
    box & operator |= (point const &p){
        min.x = std::min(min.x, p.x);
        min.y = std::min(min.y, p.y);
        max.x = std::max(max.x, p.x);
        max.y = std::max(max.y, p.y);
        return *this;
    }

    template <typename Iterator>
    box bbox(Iterator begin, Iterator end){
        box result;
        for(auto it = begin; it!= end; ++it){
            result |= *it;
        }
        return result;
    }
};







