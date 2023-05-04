#include <stdio.h>
#include <math.h>

#include "neuron.h"

class neural_network{
  static const int num_neuron = 8;
  neuron neurons[num_neuron];
  
  public:
    void init_neurons(){
      // for(int i = 0; i < num_neuron; i++){
      //   neurons[i] = neurons[i].neuron(0.01);
      // }
    }

    void compute_neural_network(){
      /*
      neurons.get_spike();
      neurons.get_weight();
      neurons.set_input_syn();
      neurons.compute_process();
      */
    }
};

int main(void){
}