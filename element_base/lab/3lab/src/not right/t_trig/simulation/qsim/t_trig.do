onerror {quit -f}
vlib work
vlog -work work t_trig.vo
vlog -work work t_trig.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.t_trig_vlg_vec_tst
vcd file -direction t_trig.msim.vcd
vcd add -internal t_trig_vlg_vec_tst/*
vcd add -internal t_trig_vlg_vec_tst/i1/*
add wave /*
run -all
