onerror {quit -f}
vlib work
vlog -work work lab_4_multireg.vo
vlog -work work lab_4_multireg.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.lab_4_multireg_vlg_vec_tst
vcd file -direction lab_4_multireg.msim.vcd
vcd add -internal lab_4_multireg_vlg_vec_tst/*
vcd add -internal lab_4_multireg_vlg_vec_tst/i1/*
add wave /*
run -all
