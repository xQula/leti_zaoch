onerror {exit -code 1}
vlib work
vlog -work work t_trig.vo
vlog -work work Waveform.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.t_trig_vlg_vec_tst -voptargs="+acc"
vcd file -direction t_trig.msim.vcd
vcd add -internal t_trig_vlg_vec_tst/*
vcd add -internal t_trig_vlg_vec_tst/i1/*
run -all
quit -f
