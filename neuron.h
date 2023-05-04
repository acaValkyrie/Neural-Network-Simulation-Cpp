#ifndef NEURON_H_
#define NEURON_H_

class neuron{
  private:
    double v;
    const double v_spike_threshold = -55.0;
    const double e_leak = -65.0;
    const double r_ext = 1;
    const double i_ext = 20.0;
    double tau;
    
    bool is_spike;
    // receive spike
    const double r_syn = 1;
    double i_syn;
    double input_syn;
    // send spike
    const double r_adp = 0.5;
    double i_adp;

    double dvdt(double _v);

  public:
    neuron();
    neuron(double _tau);
    bool get_spike();
    void set_input_syn(double _input);
    void add_input_syn(double _input);

  private:
    void calc_i_syn();
    void calc_i_adp();
    void compute_v_runge_kutta();
    void set_spike();

  public:
    void compute_process();

  private: 
    double dt;
  public:
    void set_dt(double _dt);
};

#endif// NEURON_H_