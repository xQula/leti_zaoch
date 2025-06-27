onerror {quit -f}
vlib work
vlog -work work rs_trig.vo
vlog -work work rs_trig.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.rs_trig_vlg_vec_tst
vcd file -direction rs_trig.msim.vcd
vcd add -internal rs_trig_vlg_vec_tst/*
vcd add -internal rs_trig_vlg_vec_tst/i1/*
add wave /*
run -all
