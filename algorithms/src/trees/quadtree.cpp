#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include <cstdint>

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

struct node{
    std::unique_ptr<node> children[2][2];
};

struct quadtree{
    box bbox;
    std::unique_ptr<node> root;
};


using node_id = std::uint32_t;
static constexpr node_id null = node_id(-1);
struct node{
    node_id children[2][2]{
        {null, null},
        {null, null}
    };
};

struct quadtree{
    box bbox;
    node_id root;
    std::vector<node> nodes;
};

template<typename Iterator>
node_id build_impl(quadtree &tree, box const &bbox, Iterator begin, Iterator end){
    if(begin == end)
        return null;
    node_id result = tree.nodes.size()
    tree.nodes.emplace_back();
    if (begin + 1 == end) return result;
    point center = middle(bbox.min, bbox.max);
    Iterator split_y = std::partition(
        begin,
        end,
        [center](point const & p){
            return p.y < center.y;
        }
    );

    Iterator split_x_lower = std::partition(
        begin,
        split_y,
        [center](point const &p){
            return p.x < center.x;
        }
    );


    Iterator split_x_upper = std::partition(
        split_y,
        end,
        [center](point const &p){
            return p.x < center.x;
        }
    );

    tree.nodes[result].children[0][0] = 
        build_impl(
            tree,
            {
                bbox.min,
                center
            },
            begin, 
            split_x_lower
        );

    tree.nodes[result].children[0][1] = 
        build_impl(
            tree,
            {
                {center.x, bbox.min.y},
                {bbox.max.x, center.y}
            },
            split_x_lower, 
            split_y
        );
    
    tree.nodes[result].children[1][0] =
        build_impl(
            tree,
            {
                {bbox.min.x, center.y},
                {center.x, bbox.max.y}
            },
            split_y, 
            split_x_upper
        );

    tree.nodes[result].children[1][1] =
        build_impl(
            tree,
            {
                center,
                bbox.max
            },
            split_x_upper, 
            end
        );
    
    return result;
}

template <typename Iterator>
quadtree build(Iterator begin, Iterator end){
    quadtree result;
    result.root = build_impl(result, bbox(begin, end), begin, end);
    return result;
}





