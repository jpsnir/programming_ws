#include <iostream>
#include <random>
#include <functional>
#include <time.h>
#include <unistd.h>

using namespace std;

float random(float min, float max){
    return float(rand())/RAND_MAX;
}

int main(){
    float min = 0, max = 1;
    srand(time(0));
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<float> u_dist(min, max);
    auto n = std::bind(u_dist, generator);
    
    time_t t;
    time(&t);
    cout << "time function with null argument = " << time(0) << " t = " << t << endl;
    

    cout << " ***************************** " << endl;
    for (int i = 0; i < 10; i++){
        cout << "Value = " << n() << endl;
    }

    cout << " ***************************** " << endl;
    for (int i = 0; i < 10; i++){
        cout << "Value = " << random(min, max) << endl;
    }
}