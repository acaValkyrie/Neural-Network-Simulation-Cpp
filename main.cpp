#include <stdio.h>
#include <math.h>

class neuron{
  private:
    double v;
    const double v_rest;
    const double r;
    const double i_ext;
    const double r_syn;
    double i_syn;
    const double tau;

    double connection_weight;

    double dvdt(){
      return ( -( v - v_rest ) + r * i_ext + r_syn * i_syn ) / tau;
    }

    double i_syn(double _dt, double _w){
      return i_syn * exp( -_dt / tau ) + _w;
    }

  public:
    void set_connection_weight(double _w){
      connection_weight = _w;
    }

    void set_i_syn(double _dt){
      i_syn = i_syn(_dt, connection_weight);
    }

    void calc_process(){
      // 自分に接続している相手のスパイク確認
      // input_syn = Σ spike * weight を計算
      
      // i_syn を計算
      // i_syn = i_syn*exp(-dt/tau) + input_syn

      // dv/dt を近似(Runge-Kutta)で解く
      // v を更新

      // spike チェック
      // v > theta なら 次のループで発火 & v = v_rest
    }
};



int main(void){

}