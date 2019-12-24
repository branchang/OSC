#include "w_bridge.hpp"

int w_bridge(int argc, char* argv[]){
    for (int i=0;i<argc;i++){
        std::cout<<argv[i]<<std::endl;
    }

    std::vector<CircleShape> shapes {
        CircleShape(1.0f, 2.0f, 3.0f, DrawingAPI01()),
        CircleShape(5.0f, 7.0f, 11.0f, DrawingAPI02()),
    };

    for (auto& shape:shapes){
        shape.ResizeByPercentage(2.5);
        std::cout<<shape.Draw()<<std::endl;
    }
    return 0;
}
