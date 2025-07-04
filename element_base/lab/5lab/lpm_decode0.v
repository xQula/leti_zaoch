// megafunction wizard: %LPM_DECODE%
// GENERATION: STANDARD
// VERSION: WM1.0
// MODULE: LPM_DECODE 

// ============================================================
// File Name: lpm_decode0.v
// Megafunction Name(s):
// 			LPM_DECODE
//
// Simulation Library Files(s):
// 			lpm
// ============================================================
// ************************************************************
// THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//
// 13.1.0 Build 162 10/23/2013 SJ Web Edition
// ************************************************************


//Copyright (C) 1991-2013 Altera Corporation
//Your use of Altera Corporation's design tools, logic functions 
//and other software and tools, and its AMPP partner logic 
//functions, and any output files from any of the foregoing 
//(including device programming or simulation files), and any 
//associated documentation or information are expressly subject 
//to the terms and conditions of the Altera Program License 
//Subscription Agreement, Altera MegaCore Function License 
//Agreement, or other applicable license agreement, including, 
//without limitation, that your use is for the sole purpose of 
//programming logic devices manufactured by Altera and sold by 
//Altera or its authorized distributors.  Please refer to the 
//applicable agreement for further details.


// synopsys translate_off
`timescale 1 ps / 1 ps
// synopsys translate_on
module lpm_decode0 (
	data,
	eq0,
	eq1,
	eq10,
	eq11,
	eq12,
	eq13,
	eq14,
	eq15,
	eq2,
	eq3,
	eq4,
	eq5,
	eq6,
	eq7,
	eq8,
	eq9);

	input	[3:0]  data;
	output	  eq0;
	output	  eq1;
	output	  eq10;
	output	  eq11;
	output	  eq12;
	output	  eq13;
	output	  eq14;
	output	  eq15;
	output	  eq2;
	output	  eq3;
	output	  eq4;
	output	  eq5;
	output	  eq6;
	output	  eq7;
	output	  eq8;
	output	  eq9;

	wire [15:0] sub_wire0;
	wire [6:6] sub_wire16 = sub_wire0[6:6];
	wire [15:15] sub_wire15 = sub_wire0[15:15];
	wire [9:9] sub_wire14 = sub_wire0[9:9];
	wire [5:5] sub_wire13 = sub_wire0[5:5];
	wire [14:14] sub_wire12 = sub_wire0[14:14];
	wire [10:10] sub_wire11 = sub_wire0[10:10];
	wire [1:1] sub_wire10 = sub_wire0[1:1];
	wire [8:8] sub_wire9 = sub_wire0[8:8];
	wire [4:4] sub_wire8 = sub_wire0[4:4];
	wire [13:13] sub_wire7 = sub_wire0[13:13];
	wire [0:0] sub_wire6 = sub_wire0[0:0];
	wire [7:7] sub_wire5 = sub_wire0[7:7];
	wire [3:3] sub_wire4 = sub_wire0[3:3];
	wire [12:12] sub_wire3 = sub_wire0[12:12];
	wire [2:2] sub_wire2 = sub_wire0[2:2];
	wire [11:11] sub_wire1 = sub_wire0[11:11];
	wire  eq11 = sub_wire1;
	wire  eq2 = sub_wire2;
	wire  eq12 = sub_wire3;
	wire  eq3 = sub_wire4;
	wire  eq7 = sub_wire5;
	wire  eq0 = sub_wire6;
	wire  eq13 = sub_wire7;
	wire  eq4 = sub_wire8;
	wire  eq8 = sub_wire9;
	wire  eq1 = sub_wire10;
	wire  eq10 = sub_wire11;
	wire  eq14 = sub_wire12;
	wire  eq5 = sub_wire13;
	wire  eq9 = sub_wire14;
	wire  eq15 = sub_wire15;
	wire  eq6 = sub_wire16;

	lpm_decode	LPM_DECODE_component (
				.data (data),
				.eq (sub_wire0)
				// synopsys translate_off
				,
				.aclr (),
				.clken (),
				.clock (),
				.enable ()
				// synopsys translate_on
				);
	defparam
		LPM_DECODE_component.lpm_decodes = 16,
		LPM_DECODE_component.lpm_type = "LPM_DECODE",
		LPM_DECODE_component.lpm_width = 4;


endmodule

// ============================================================
// CNX file retrieval info
// ============================================================
// Retrieval info: PRIVATE: BaseDec NUMERIC "1"
// Retrieval info: PRIVATE: EnableInput NUMERIC "0"
// Retrieval info: PRIVATE: INTENDED_DEVICE_FAMILY STRING "Cyclone III"
// Retrieval info: PRIVATE: LPM_PIPELINE NUMERIC "0"
// Retrieval info: PRIVATE: Latency NUMERIC "0"
// Retrieval info: PRIVATE: SYNTH_WRAPPER_GEN_POSTFIX STRING "0"
// Retrieval info: PRIVATE: aclr NUMERIC "0"
// Retrieval info: PRIVATE: clken NUMERIC "0"
// Retrieval info: PRIVATE: eq0 NUMERIC "1"
// Retrieval info: PRIVATE: eq1 NUMERIC "1"
// Retrieval info: PRIVATE: eq10 NUMERIC "1"
// Retrieval info: PRIVATE: eq11 NUMERIC "1"
// Retrieval info: PRIVATE: eq12 NUMERIC "1"
// Retrieval info: PRIVATE: eq13 NUMERIC "1"
// Retrieval info: PRIVATE: eq14 NUMERIC "1"
// Retrieval info: PRIVATE: eq15 NUMERIC "1"
// Retrieval info: PRIVATE: eq2 NUMERIC "1"
// Retrieval info: PRIVATE: eq3 NUMERIC "1"
// Retrieval info: PRIVATE: eq4 NUMERIC "1"
// Retrieval info: PRIVATE: eq5 NUMERIC "1"
// Retrieval info: PRIVATE: eq6 NUMERIC "1"
// Retrieval info: PRIVATE: eq7 NUMERIC "1"
// Retrieval info: PRIVATE: eq8 NUMERIC "1"
// Retrieval info: PRIVATE: eq9 NUMERIC "1"
// Retrieval info: PRIVATE: nBit NUMERIC "4"
// Retrieval info: PRIVATE: new_diagram STRING "1"
// Retrieval info: LIBRARY: lpm lpm.lpm_components.all
// Retrieval info: CONSTANT: LPM_DECODES NUMERIC "16"
// Retrieval info: CONSTANT: LPM_TYPE STRING "LPM_DECODE"
// Retrieval info: CONSTANT: LPM_WIDTH NUMERIC "4"
// Retrieval info: USED_PORT: @eq 0 0 16 0 OUTPUT NODEFVAL "@eq[15..0]"
// Retrieval info: USED_PORT: data 0 0 4 0 INPUT NODEFVAL "data[3..0]"
// Retrieval info: USED_PORT: eq0 0 0 0 0 OUTPUT NODEFVAL "eq0"
// Retrieval info: USED_PORT: eq1 0 0 0 0 OUTPUT NODEFVAL "eq1"
// Retrieval info: USED_PORT: eq10 0 0 0 0 OUTPUT NODEFVAL "eq10"
// Retrieval info: USED_PORT: eq11 0 0 0 0 OUTPUT NODEFVAL "eq11"
// Retrieval info: USED_PORT: eq12 0 0 0 0 OUTPUT NODEFVAL "eq12"
// Retrieval info: USED_PORT: eq13 0 0 0 0 OUTPUT NODEFVAL "eq13"
// Retrieval info: USED_PORT: eq14 0 0 0 0 OUTPUT NODEFVAL "eq14"
// Retrieval info: USED_PORT: eq15 0 0 0 0 OUTPUT NODEFVAL "eq15"
// Retrieval info: USED_PORT: eq2 0 0 0 0 OUTPUT NODEFVAL "eq2"
// Retrieval info: USED_PORT: eq3 0 0 0 0 OUTPUT NODEFVAL "eq3"
// Retrieval info: USED_PORT: eq4 0 0 0 0 OUTPUT NODEFVAL "eq4"
// Retrieval info: USED_PORT: eq5 0 0 0 0 OUTPUT NODEFVAL "eq5"
// Retrieval info: USED_PORT: eq6 0 0 0 0 OUTPUT NODEFVAL "eq6"
// Retrieval info: USED_PORT: eq7 0 0 0 0 OUTPUT NODEFVAL "eq7"
// Retrieval info: USED_PORT: eq8 0 0 0 0 OUTPUT NODEFVAL "eq8"
// Retrieval info: USED_PORT: eq9 0 0 0 0 OUTPUT NODEFVAL "eq9"
// Retrieval info: CONNECT: @data 0 0 4 0 data 0 0 4 0
// Retrieval info: CONNECT: eq0 0 0 0 0 @eq 0 0 1 0
// Retrieval info: CONNECT: eq1 0 0 0 0 @eq 0 0 1 1
// Retrieval info: CONNECT: eq10 0 0 0 0 @eq 0 0 1 10
// Retrieval info: CONNECT: eq11 0 0 0 0 @eq 0 0 1 11
// Retrieval info: CONNECT: eq12 0 0 0 0 @eq 0 0 1 12
// Retrieval info: CONNECT: eq13 0 0 0 0 @eq 0 0 1 13
// Retrieval info: CONNECT: eq14 0 0 0 0 @eq 0 0 1 14
// Retrieval info: CONNECT: eq15 0 0 0 0 @eq 0 0 1 15
// Retrieval info: CONNECT: eq2 0 0 0 0 @eq 0 0 1 2
// Retrieval info: CONNECT: eq3 0 0 0 0 @eq 0 0 1 3
// Retrieval info: CONNECT: eq4 0 0 0 0 @eq 0 0 1 4
// Retrieval info: CONNECT: eq5 0 0 0 0 @eq 0 0 1 5
// Retrieval info: CONNECT: eq6 0 0 0 0 @eq 0 0 1 6
// Retrieval info: CONNECT: eq7 0 0 0 0 @eq 0 0 1 7
// Retrieval info: CONNECT: eq8 0 0 0 0 @eq 0 0 1 8
// Retrieval info: CONNECT: eq9 0 0 0 0 @eq 0 0 1 9
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0.v TRUE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0.inc FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0.cmp FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0.bsf TRUE FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0_inst.v FALSE
// Retrieval info: GEN_FILE: TYPE_NORMAL lpm_decode0_bb.v TRUE
// Retrieval info: LIB_FILE: lpm
