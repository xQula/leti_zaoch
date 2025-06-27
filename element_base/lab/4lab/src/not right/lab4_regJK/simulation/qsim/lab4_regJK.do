onerror {quit -f}
vlib work
vlog -work work lab4_regJK.vo
vlog -work work lab4_regJK.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.lab4_regJK_vlg_vec_tst
vcd file -direction lab4_regJK.msim.vcd
vcd add -internal lab4_regJK_vlg_vec_tst/*
vcd add -internal lab4_regJK_vlg_vec_tst/i1/*
add wave /*
run -all
