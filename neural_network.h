#ifndef NEURAL_NETWORK_H_
#define NEURAL_NETWORK_H_

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
     /*neuron[0] input to these*/ {   0,    1,    0,    1,   0, 1, 0, 1}, 
     /*neuron[1] input to these*/ {0.05,    0,    1,    0,   1, 0, 1, 0}, 
     /*neuron[2] input to these*/ {   0,    1,    0,    1,   0, 1, 0, 1}, 
     /*neuron[3] input to these*/ {   1,    0,    1,    0,   1, 0, 1, 0}, 
     /*neuron[4] input to these*/ {   0,    1,    0,    1,   0, 1, 0, 1}, 
     /*neuron[5] input to these*/ {   1,    0,    1,    0,   1, 0, 0.3, 0}, 
     /*neuron[6] input to these*/ {   0,    1,    0,    0.1,   0, 1, 0, 1}, 
     /*neuron[7] input to these*/ {   1,    0,    1,    0,   1, 0, 1, 0}
     };
    
  public:
    void compute_neural_network();
    void set_all_neuron_dt(double _dt);
    int get_all_spike_bit();
};

#endif // NEURAL_NETWORK_H_