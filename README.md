# Neural Network Simulation with C++ for Arduino
## calc method
自分に接続している相手のスパイク確認  
input_syn = Σ spike * weight を計算

i_syn を計算  
i_syn = i_syn*exp(-dt/tau) + input_syn

dv/dt を近似(Runge-Kutta)で解く  
v を更新

spike チェック  
v > theta なら 次のループで発火 & v = v_rest