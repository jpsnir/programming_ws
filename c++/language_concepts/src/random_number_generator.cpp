#include <iostream>
#include <random>
#include <functional>
#include <time.h>
#include <unistd.h>

using namespace std;

float random(float min, float max){
    srand(time(0));
    
}

int main(){
    float min = 0, max = 1;
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<float> u_dist(min, max);
    auto n = std::bind(u_dist, generator);
    for (int i = 0; i < 10; i ++){
        time_t t;
        cout << "time = " << time(0) << " delta offset = " << t << endl;
        usleep(1000000);
    }

    for (int i = 0; i < 10; i++){
        cout << "Value = " << n() << endl;
    }
}