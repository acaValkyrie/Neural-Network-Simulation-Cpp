#include "neural_network.h"

void neural_network::compute_neural_network(){
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

void neural_network::set_all_neuron_dt(double _dt){
  for(int i = 0; i < num_neuron; i++){
    neurons[i].set_dt(_dt);
  }
}

int neural_network::get_all_spike_bit(){
  int spike_bit = 0b0;
  for(int i = 0; i < num_neuron; i++){
    // shift to left 1bit
    spike_bit <<= 1;
    // add spike_bit
    spike_bit += neurons[i].get_spike();
  }
  return spike_bit;
}