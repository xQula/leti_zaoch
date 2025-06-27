onerror {quit -f}
vlib work
vlog -work work Lab2_seven_seg.vo
vlog -work work Lab2_seven_seg.vt
vsim -novopt -c -t 1ps -L cycloneii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.seven_seg_vlg_vec_tst
vcd file -direction Lab2_seven_seg.msim.vcd
vcd add -internal seven_seg_vlg_vec_tst/*
vcd add -internal seven_seg_vlg_vec_tst/i1/*
add wave /*
run -all
