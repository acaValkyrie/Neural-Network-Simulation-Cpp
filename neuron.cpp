#include "neuron.h"
#include <math.h>

double neuron::dvdt(double _v){
  return ( -( _v - e_leak ) + r_ext*i_ext + r_syn*i_syn - r_adp*i_adp ) / tau;
}
neuron::neuron(){
  // set param
  tau = 0.01;

  // init variables
  v = e_leak;
  is_spike = false;
  i_syn = 0.0;
  input_syn = 0.0;
  i_adp = 0.0;
}

neuron::neuron(double _tau){
  // set param
  tau = _tau;

  // init variables
  v = e_leak;
  is_spike = false;
  i_syn = 0.0;
  input_syn = 0.0;
  i_adp = 0.0;
}

bool neuron::get_spike(){
  return is_spike;
}

void neuron::set_input_syn(double _input){
  // _input = Σ get_spike()*weight_to_me_from_others
  input_syn = _input;
}

void neuron::add_input_syn(double _input){
  input_syn += _input;
}

void neuron::calc_i_syn(){
  i_syn = i_syn*exp(-dt/tau) + input_syn;
}

void neuron::calc_i_adp(){
  i_adp = i_adp*exp(-dt/tau) + is_spike;
}

void neuron::compute_v_runge_kutta(){
  double v_current = v;
  double k1 = dt*dvdt(v_current         );
  double k2 = dt*dvdt(v_current + 0.5*k1);
  double k3 = dt*dvdt(v_current + 0.5*k2);
  double k4 = dt*dvdt(v_current +     k3);
  v = v_current + (k1 + 2*k2 + 2*k3 + k4)/6.0;
}

void neuron::set_spike(){
  if(v > v_spike_threshold){
    is_spike = true;
    v = e_leak;
    return;
  }

  is_spike = false;
  return;
}

#include <stdio.h>

void neuron::compute_process(){
  // 自分に接続している相手のスパイク確認
  // input_syn = Σ spike * weight を計算
  // set_input_syn()
  //   get_spike()
  //   get_weight()
  
  calc_i_syn();
  calc_i_adp();

  // compute v from dvdt and runge-kutta approximate
  compute_v_runge_kutta();

  // spike チェック
  set_spike();

  printf("%f, ", v);
}

void neuron::set_dt(double _dt){
  dt = _dt;
}