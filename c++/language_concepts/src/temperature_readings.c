#include <stdio.h>
#include <math.h>
#include <assert.h>

// Function to calculate the temperature from LSB value
double correctedLSB_to_degreesC(double a_0, double decay_constant, double reading) {
  assert(decay_constant != 0);
  assert(reading > 0 && a_0 > 0);
  return (1.0/decay_constant)*log(reading/a_0);
}


int main(){

    double a_0 = 50342.0;
    double decay_constant = -0.0401;
    double correctedLSB[] = {51197, 46911, 39518, 33423, 27289};
    double temperature[] = {0, 2, 6, 10, 15};
    for (int i = 0; i < sizeof(correctedLSB)/sizeof(correctedLSB[0]); i++){
      double predicted = correctedLSB_to_degreesC(a_0, decay_constant, correctedLSB[i]);
      printf("%d, Predicted : [%lf], actual [%lf], the difference = %lf \n ", i, predicted, temperature[i], temperature[i] - predicted);     
    }
}
