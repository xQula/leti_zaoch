onerror {exit -code 1}
vlib work
vlog -work work jk_trig.vo
vlog -work work Waveform1.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.jk_trig_vlg_vec_tst -voptargs="+acc"
vcd file -direction jk_trig.msim.vcd
vcd add -internal jk_trig_vlg_vec_tst/*
vcd add -internal jk_trig_vlg_vec_tst/i1/*
run -all
quit -f
