#include <stdio.h>
#include "neural_network.h"

int main(void){
  neural_network nn;
  nn.set_all_neuron_dt(0.001 /*s*/);
  for(int i = 0; i < 100; i++){
    nn.compute_neural_network();
    int spike_bits = nn.get_all_spike_bit();
    printf("\n");
  }
}