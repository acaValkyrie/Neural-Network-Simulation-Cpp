#include <stdio.h>
#include <math.h>

class neuron{
  private:
    double v;
    const double e_leak = -65.0;
    const double r_ext = 1;
    const double i_ext = 20.0;
    const double tau;
    
    bool is_spike;
    // receive spike
    const double r_syn = 1;
    double i_syn;
    double input_syn;
    // send spike
    const double r_adp = 0.5;
    double i_adp;

    double dvdt(double _v, double _t){
      return ( -( _v - e_leak ) + r_ext*i_ext + r_syn*i_syn - r_adp*i_adp ) / tau;
    }

  public:
    neuron(double _tau){
      // set param
      tau = _tau;

      // init variables
      v = e_leak;
      is_spike = false;
      i_syn = 0.0;
      input_syn = 0.0;
      i_adp = 0.0;
    }

    bool get_spike(){
      return is_spike;
    }

    void set_input_syn(double _input){
      // _input = Σ get_spike()*weight_to_me_from_others
      input_syn = _input;
    }

  private:
    void calc_i_syn(){
      i_syn = i_syn*exp(-dt/tau) + input_syn;
    }

    void calc_i_adp(){
      i_adp = i_adp*exp(-dt/tau) + is_spike;
    }

    void compute_v_runge_kutta(){
      v_current = v;
      k1 = dt*dvdt(v_current         );
      k2 = dt*dvdt(v_current + 0.5*k1);
      k3 = dt*dvdt(v_current + 0.5*k2);
      k4 = dt*dvdt(v_current +     k3);
      v = v_current + (k1 + 2*k2 + 2*k3 + k4)/6.0;
    }

    void set_spike(){
      if(v > v_spike_threshold){
        is_spike = true;
        v = e_leak;
        return;
      }

      is_spike = false;
      return;
    }

  public:
    void calc_process(){
      // 自分に接続している相手のスパイク確認
      // input_syn = Σ spike * weight を計算
      // set_input_syn()
      //   get_spike()
      //   get_weight()
      
      // i_syn を計算
      // i_syn = i_syn*exp(-dt/tau) + input_syn
      // calc_i_syn()
      calc_i_syn();

      // i_adp を計算
      // i_adp = i_adp*exp(-dt/tau) + spike
      // calc_i_adp()
      calc_i_adp();

      // dv/dt を近似(Runge-Kutta)で解く
      // v を更新
      compute_v_runge_kutta();

      // spike チェック
      // v > theta なら 次のループで発火 & v = e_leak
      set_spike();
    }
};

class neural_network{
  const int num_neuron = 8;
  neuron neurons[num_neuron];
  
  public:
    void init_neurons(){
      for(int i = 0; i < num_neuron; i++){
        neurons[i] = neuron(0.01);
      }
    }

    void compute_neural_network(){
      /*
      neurons.get_spike();
      neurons.get_weight();
      neurons.set_input_syn();
      neurons.calc_process();
      */
    }
}

int main(void){

}