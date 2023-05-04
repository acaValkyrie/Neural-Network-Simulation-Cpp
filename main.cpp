#include <stdio.h>
#include "neuron.h"

class neural_network{
  private:
    static const int num_neuron = 8;
    neuron neurons[num_neuron] {0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};
    
    /*
    自分が入力しているシナプスの重み -> 
    [[0  , 0.1, 0, ... , 0.05],
     [0.2, 0, ...      , 0   ]
     .
     .
    ]
    */
    const double neuron_weights[num_neuron][num_neuron] = {
      {0, 1, 0, 1, 0, 1, 0, 1}, 
      {0, 0, 0, 1, 0, 1, 0, 1}, 
      {0, 1, 0, 1, 0, 1, 0, 1}, 
      {0, 1, 0, 0, 0, 1, 0, 1}, 
      {0, 1, 0, 1, 0, 1, 0, 1}, 
      {0, 1, 0, 1, 0, 0, 0, 1}, 
      {0, 1, 0, 1, 0, 1, 0, 1}, 
      {0, 1, 0, 1, 0, 1, 0, 0}};
    
  public:
    void compute_neural_network(){
      // initialize input_syn
      for(int i = 0; i < num_neuron; i++){
        neurons[i].set_input_syn(0.0);
      }

      // synapse input
      for(int i = 0; i < num_neuron; i++){
        // spike check
        if ( ! neurons[i].get_spike() ) continue;

        for(int u/*you*/ = 0; u < num_neuron; u++){
          double synapse_input_from_i = neuron_weights[i][u];
          neurons[u].add_input_syn(synapse_input_from_i);
        }
      }

      // compute v
      for(int i = 0; i < num_neuron; i++){
        neurons[i].compute_process();
      }
    }

    void set_all_neuron_dt(double _dt){
      for(int i = 0; i < num_neuron; i++){
        neurons[i].set_dt(_dt);
      }
    }

    int get_all_spike_bit(){
      int spike_bit = 0b0;
      for(int i = 0; i < num_neuron; i++){
        // shift to left 1bit
        spike_bit <<= 1;
        // add spike_bit
        spike_bit += neurons[i].get_spike();
      }
      return spike_bit;
    }
};

int main(void){
  
  neural_network nn;
  nn.set_all_neuron_dt(0.001 /*s*/);
  for(int i = 0; i < 100; i++){
    nn.compute_neural_network();
    int spike_bits = nn.get_all_spike_bit();
    
    printf("%d\n", spike_bits);
  }
  
}