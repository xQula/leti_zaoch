-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"

-- DATE "01/22/2025 22:14:20"

-- 
-- Device: Altera EP3C16F484C6 Package FBGA484
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY CYCLONEIII;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE CYCLONEIII.CYCLONEIII_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	Lab6 IS
    PORT (
	D2 : OUT std_logic;
	C : IN std_logic;
	R : IN std_logic;
	D4 : OUT std_logic;
	D0 : OUT std_logic;
	D6 : OUT std_logic;
	D1 : OUT std_logic;
	D3 : OUT std_logic;
	D5 : OUT std_logic
	);
END Lab6;

-- Design Ports Information
-- D2	=>  Location: PIN_P4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D4	=>  Location: PIN_R2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D0	=>  Location: PIN_P2,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D6	=>  Location: PIN_L7,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D1	=>  Location: PIN_P1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D3	=>  Location: PIN_M4,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- D5	=>  Location: PIN_M5,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- R	=>  Location: PIN_N1,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- C	=>  Location: PIN_G2,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF Lab6 IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_D2 : std_logic;
SIGNAL ww_C : std_logic;
SIGNAL ww_R : std_logic;
SIGNAL ww_D4 : std_logic;
SIGNAL ww_D0 : std_logic;
SIGNAL ww_D6 : std_logic;
SIGNAL ww_D1 : std_logic;
SIGNAL ww_D3 : std_logic;
SIGNAL ww_D5 : std_logic;
SIGNAL \C~inputclkctrl_INCLK_bus\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \D2~output_o\ : std_logic;
SIGNAL \D4~output_o\ : std_logic;
SIGNAL \D0~output_o\ : std_logic;
SIGNAL \D6~output_o\ : std_logic;
SIGNAL \D1~output_o\ : std_logic;
SIGNAL \D3~output_o\ : std_logic;
SIGNAL \D5~output_o\ : std_logic;
SIGNAL \R~input_o\ : std_logic;
SIGNAL \C~input_o\ : std_logic;
SIGNAL \C~inputclkctrl_outclk\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|aclr_actual~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]~1_combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ : std_logic;
SIGNAL \inst6|inst2~1_combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ : std_logic;
SIGNAL \inst6|inst2~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\ : std_logic;
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ : std_logic;
SIGNAL \inst6|inst1~0_combout\ : std_logic;
SIGNAL \inst6|inst2~2_combout\ : std_logic;
SIGNAL \inst6|inst3~0_combout\ : std_logic;
SIGNAL \inst6|inst7~0_combout\ : std_logic;
SIGNAL \inst6|inst4~13_combout\ : std_logic;
SIGNAL \inst6|inst4~14_combout\ : std_logic;
SIGNAL \inst6|inst5~2_combout\ : std_logic;
SIGNAL \inst6|inst5~combout\ : std_logic;
SIGNAL \inst6|inst1~1_combout\ : std_logic;
SIGNAL \inst6|inst1~4_combout\ : std_logic;
SIGNAL \inst6|inst1~2_combout\ : std_logic;
SIGNAL \inst6|inst1~3_combout\ : std_logic;
SIGNAL \inst6|inst1~5_combout\ : std_logic;
SIGNAL \inst6|inst7~1_combout\ : std_logic;
SIGNAL \inst6|inst7~2_combout\ : std_logic;
SIGNAL \inst6|inst2~3_combout\ : std_logic;
SIGNAL \inst6|inst4~17_combout\ : std_logic;
SIGNAL \inst6|inst4~18_combout\ : std_logic;
SIGNAL \inst6|inst4~16_combout\ : std_logic;
SIGNAL \inst6|inst4~15_combout\ : std_logic;
SIGNAL \inst6|inst6~0_combout\ : std_logic;
SIGNAL \inst6|inst6~combout\ : std_logic;
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|safe_q\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|latch_signal\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\ : std_logic;

BEGIN

D2 <= ww_D2;
ww_C <= C;
ww_R <= R;
D4 <= ww_D4;
D0 <= ww_D0;
D6 <= ww_D6;
D1 <= ww_D1;
D3 <= ww_D3;
D5 <= ww_D5;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;

\C~inputclkctrl_INCLK_bus\ <= (vcc & vcc & vcc & \C~input_o\);
\inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\ <= NOT \inst3|LPM_COUNTER_component|auto_generated|aclr_actual~0_combout\;

-- Location: IOOBUF_X0_Y10_N23
\D2~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst3~0_combout\,
	devoe => ww_devoe,
	o => \D2~output_o\);

-- Location: IOOBUF_X0_Y10_N2
\D4~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst5~combout\,
	devoe => ww_devoe,
	o => \D4~output_o\);

-- Location: IOOBUF_X0_Y11_N16
\D0~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst1~5_combout\,
	devoe => ww_devoe,
	o => \D0~output_o\);

-- Location: IOOBUF_X0_Y11_N2
\D6~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst7~2_combout\,
	devoe => ww_devoe,
	o => \D6~output_o\);

-- Location: IOOBUF_X0_Y11_N23
\D1~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst2~3_combout\,
	devoe => ww_devoe,
	o => \D1~output_o\);

-- Location: IOOBUF_X0_Y12_N2
\D3~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst4~15_combout\,
	devoe => ww_devoe,
	o => \D3~output_o\);

-- Location: IOOBUF_X0_Y11_N9
\D5~output\ : cycloneiii_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false")
-- pragma translate_on
PORT MAP (
	i => \inst6|inst6~combout\,
	devoe => ww_devoe,
	o => \D5~output_o\);

-- Location: IOIBUF_X0_Y12_N22
\R~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_R,
	o => \R~input_o\);

-- Location: IOIBUF_X0_Y14_N1
\C~input\ : cycloneiii_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_C,
	o => \C~input_o\);

-- Location: CLKCTRL_G4
\C~inputclkctrl\ : cycloneiii_clkctrl
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	ena_register_mode => "none")
-- pragma translate_on
PORT MAP (
	inclk => \C~inputclkctrl_INCLK_bus\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	outclk => \C~inputclkctrl_outclk\);

-- Location: LCCOMB_X2_Y12_N8
\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\ = (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1) & (!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\)) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1) & ((\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (GND)))
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ = CARRY((!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\) # (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011110000111111",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datad => VCC,
	cin => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	cout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\);

-- Location: LCCOMB_X2_Y12_N10
\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\ = (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2) & (\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ $ (GND))) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2) & (!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\ & VCC))
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\ = CARRY((\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2) & !\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010010100001010",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datad => VCC,
	cin => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~COUT\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	cout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\);

-- Location: LCCOMB_X2_Y12_N22
\inst3|LPM_COUNTER_component|auto_generated|aclr_actual~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|aclr_actual~0_combout\ = (\R~input_o\) # (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \R~input_o\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	combout => \inst3|LPM_COUNTER_component|auto_generated|aclr_actual~0_combout\);

-- Location: FF_X2_Y12_N11
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \C~inputclkctrl_outclk\,
	d => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~combout\,
	clrn => \inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2));

-- Location: LCCOMB_X2_Y12_N26
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ = (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & (!\R~input_o\ & (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1) & 
-- \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \R~input_o\,
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datad => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\);

-- Location: LCCOMB_X2_Y12_N4
\inst3|LPM_COUNTER_component|auto_generated|latch_signal[3]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3) = (\R~input_o\) # ((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \R~input_o\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datad => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3),
	combout => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3));

-- Location: LCCOMB_X2_Y12_N12
\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\ = \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3) $ (!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100001111000011",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	datab => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3),
	cin => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita2~COUT\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\);

-- Location: LCCOMB_X2_Y12_N28
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]~0_combout\ = \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3) $ (!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101001010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3),
	datad => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita3~combout\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]~0_combout\);

-- Location: FF_X2_Y12_N29
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \C~inputclkctrl_outclk\,
	d => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[3]~0_combout\,
	clrn => \inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3));

-- Location: LCCOMB_X2_Y12_N2
\inst3|LPM_COUNTER_component|auto_generated|pre_hazard[3]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3) = \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3) $ (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3),
	datad => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3),
	combout => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3));

-- Location: LCCOMB_X2_Y12_N0
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & (\R~input_o\)) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & 
-- (!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0) & ((\R~input_o\) # (\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1000101110001010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \R~input_o\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datac => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datad => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3),
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\);

-- Location: LCCOMB_X2_Y12_N24
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w[3]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100110000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3));

-- Location: LCCOMB_X2_Y12_N18
\inst3|LPM_COUNTER_component|auto_generated|latch_signal[0]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0) = (\R~input_o\) # ((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \R~input_o\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datad => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0),
	combout => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0));

-- Location: LCCOMB_X2_Y12_N6
\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\ = \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0) $ (GND)
-- \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\ = CARRY(!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101001010101",
	sum_lutc_input => "cin")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datad => VCC,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	cout => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~COUT\);

-- Location: LCCOMB_X2_Y12_N20
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]~1_combout\ = \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0) $ (!\inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101001010101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0),
	datad => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita0~combout\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]~1_combout\);

-- Location: FF_X2_Y12_N21
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \C~inputclkctrl_outclk\,
	d => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[0]~1_combout\,
	clrn => \inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0));

-- Location: LCCOMB_X2_Y12_N30
\inst3|LPM_COUNTER_component|auto_generated|pre_hazard[0]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0) = \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0) $ (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0101010110101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0),
	datad => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0),
	combout => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0));

-- Location: FF_X2_Y12_N9
\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \C~inputclkctrl_outclk\,
	d => \inst3|LPM_COUNTER_component|auto_generated|counter_comb_bita1~combout\,
	clrn => \inst3|LPM_COUNTER_component|auto_generated|ALT_INV_aclr_actual~0_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1));

-- Location: LCCOMB_X2_Y11_N24
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\ = (!\R~input_o\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3)) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datac => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3),
	datad => \R~input_o\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\);

-- Location: LCCOMB_X2_Y11_N6
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\ = (\R~input_o\) # (((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\) # (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2))) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \R~input_o\,
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\);

-- Location: LCCOMB_X2_Y11_N2
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0) & 
-- (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3) $ (!\inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111001011110001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datad => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3),
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\);

-- Location: LCCOMB_X2_Y11_N20
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ = (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1) & 
-- (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2) & !\R~input_o\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000000000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datad => \R~input_o\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\);

-- Location: LCCOMB_X1_Y11_N26
\inst6|inst2~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst2~1_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ & (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & 
-- ((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\)))) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ & 
-- (((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000011101110111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst2~1_combout\);

-- Location: LCCOMB_X2_Y11_N22
\inst3|LPM_COUNTER_component|auto_generated|safe_q[2]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2) = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((\R~input_o\) # (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datad => \R~input_o\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2));

-- Location: LCCOMB_X2_Y11_N12
\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((\R~input_o\) # (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111110101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datad => \R~input_o\,
	combout => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\);

-- Location: LCCOMB_X1_Y11_N20
\inst6|inst2~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst2~0_combout\ = (\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ & (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\)) # (!\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ & 
-- (((\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2)) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010110010101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	datab => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datac => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst2~0_combout\);

-- Location: LCCOMB_X2_Y11_N8
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\ = (!\R~input_o\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1) & 
-- !\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010101011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datac => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datad => \R~input_o\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\);

-- Location: LCCOMB_X1_Y11_N8
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w\(3) = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\ & \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w\(3));

-- Location: LCCOMB_X2_Y11_N30
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & (((\R~input_o\)))) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & 
-- (!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3) & ((\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0)) # (\R~input_o\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111100000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datac => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3),
	datad => \R~input_o\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\);

-- Location: LCCOMB_X2_Y11_N16
\inst6|inst1~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~0_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ & (((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\ & 
-- !\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\)))) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ & (((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\)) # 
-- (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0001010100011111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	combout => \inst6|inst1~0_combout\);

-- Location: LCCOMB_X1_Y11_N18
\inst6|inst2~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst2~2_combout\ = (\inst6|inst2~1_combout\ & (\inst6|inst2~0_combout\ & (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w\(3) & \inst6|inst1~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000100000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst2~1_combout\,
	datab => \inst6|inst2~0_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w\(3),
	datad => \inst6|inst1~0_combout\,
	combout => \inst6|inst2~2_combout\);

-- Location: LCCOMB_X2_Y11_N14
\inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w[3]\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3) = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # 
-- ((!\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0) & !\inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010101100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(0),
	datac => \inst3|LPM_COUNTER_component|auto_generated|pre_hazard\(3),
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	combout => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3));

-- Location: LCCOMB_X2_Y11_N0
\inst6|inst3~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst3~0_combout\ = (((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3))) # (!\inst6|inst2~2_combout\)) # 
-- (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\,
	datab => \inst6|inst2~2_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3),
	combout => \inst6|inst3~0_combout\);

-- Location: LCCOMB_X1_Y11_N30
\inst6|inst7~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst7~0_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ & (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & 
-- (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\))) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\ & (((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\) # 
-- (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000011101010111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst7~0_combout\);

-- Location: LCCOMB_X2_Y11_N18
\inst6|inst4~13\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~13_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\) # (!\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010000010101010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\,
	datad => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	combout => \inst6|inst4~13_combout\);

-- Location: LCCOMB_X2_Y11_N4
\inst6|inst4~14\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~14_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\ & (\inst6|inst7~0_combout\ & !\inst6|inst4~13_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000000010001000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\,
	datab => \inst6|inst7~0_combout\,
	datad => \inst6|inst4~13_combout\,
	combout => \inst6|inst4~14_combout\);

-- Location: LCCOMB_X1_Y11_N0
\inst6|inst5~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst5~2_combout\ = (!\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ & ((\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2) & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\))) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2) & (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011000000100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	datab => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\,
	datad => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	combout => \inst6|inst5~2_combout\);

-- Location: LCCOMB_X1_Y11_N4
\inst6|inst5\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst5~combout\ = ((\inst6|inst5~2_combout\) # ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\ & \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\))) # (!\inst6|inst4~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110111011101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst4~14_combout\,
	datab => \inst6|inst5~2_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode91w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst5~combout\);

-- Location: LCCOMB_X1_Y11_N28
\inst6|inst1~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~1_combout\ = (!\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\) # ((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\ & 
-- \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2)))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000111100000100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	datab => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datac => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst1~1_combout\);

-- Location: LCCOMB_X1_Y11_N22
\inst6|inst1~4\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~4_combout\ = ((\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2) & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\))) # (!\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2) & 
-- (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\))) # (!\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111101011111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	datac => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\,
	datad => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	combout => \inst6|inst1~4_combout\);

-- Location: LCCOMB_X2_Y11_N26
\inst6|inst1~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~2_combout\ = (\inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\) # ((\inst3|LPM_COUNTER_component|auto_generated|safe_q\(2)) # ((!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\ & 
-- !\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111011101111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|safe_q[1]~1_combout\,
	datab => \inst3|LPM_COUNTER_component|auto_generated|safe_q\(2),
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode112w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	combout => \inst6|inst1~2_combout\);

-- Location: LCCOMB_X2_Y11_N28
\inst6|inst1~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~3_combout\ = (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3) & (\inst6|inst1~0_combout\ & (\inst6|inst1~2_combout\ & \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100000000000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datab => \inst6|inst1~0_combout\,
	datac => \inst6|inst1~2_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode71w[3]~0_combout\,
	combout => \inst6|inst1~3_combout\);

-- Location: LCCOMB_X1_Y11_N12
\inst6|inst1~5\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst1~5_combout\ = (\inst6|inst1~1_combout\) # ((!\inst6|inst1~3_combout\) # (!\inst6|inst1~4_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst6|inst1~1_combout\,
	datac => \inst6|inst1~4_combout\,
	datad => \inst6|inst1~3_combout\,
	combout => \inst6|inst1~5_combout\);

-- Location: LCCOMB_X1_Y11_N10
\inst6|inst7~1\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst7~1_combout\ = (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\) # 
-- (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001100100010",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	combout => \inst6|inst7~1_combout\);

-- Location: LCCOMB_X1_Y11_N16
\inst6|inst7~2\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst7~2_combout\ = (\inst6|inst7~1_combout\) # ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3)) # ((!\inst6|inst1~3_combout\) # (!\inst6|inst2~1_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1110111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst7~1_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode122w\(3),
	datac => \inst6|inst2~1_combout\,
	datad => \inst6|inst1~3_combout\,
	combout => \inst6|inst7~2_combout\);

-- Location: LCCOMB_X1_Y11_N14
\inst6|inst2~3\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst2~3_combout\ = ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ & !\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\)) # (!\inst6|inst2~2_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0011001111110011",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst6|inst2~2_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	combout => \inst6|inst2~3_combout\);

-- Location: LCCOMB_X2_Y12_N16
\inst6|inst4~17\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~17_combout\ = \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0) $ (\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3) $ (\inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0) $ 
-- (!\inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1001011001101001",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0),
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(3),
	datac => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0),
	datad => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(3),
	combout => \inst6|inst4~17_combout\);

-- Location: LCCOMB_X2_Y12_N14
\inst6|inst4~18\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~18_combout\ = (\inst6|inst4~17_combout\ & ((\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0) $ (\inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0))) # 
-- (!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0111101100000000",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(0),
	datab => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(1),
	datac => \inst3|LPM_COUNTER_component|auto_generated|latch_signal\(0),
	datad => \inst6|inst4~17_combout\,
	combout => \inst6|inst4~18_combout\);

-- Location: LCCOMB_X2_Y11_N10
\inst6|inst4~16\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~16_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3)) # ((\R~input_o\) # ((!\inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2) & \inst6|inst4~18_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111111111110100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst3|LPM_COUNTER_component|auto_generated|counter_reg_bit\(2),
	datab => \inst6|inst4~18_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode61w\(3),
	datad => \R~input_o\,
	combout => \inst6|inst4~16_combout\);

-- Location: LCCOMB_X1_Y11_N2
\inst6|inst4~15\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst4~15_combout\ = ((\inst6|inst4~16_combout\) # ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\))) # (!\inst6|inst4~14_combout\)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1111110111110101",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst4~14_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	datac => \inst6|inst4~16_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode21w[3]~0_combout\,
	combout => \inst6|inst4~15_combout\);

-- Location: LCCOMB_X1_Y11_N24
\inst6|inst6~0\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst6~0_combout\ = (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ & ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\) # 
-- ((\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & !\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\)))) # (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\ & 
-- (\inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\ & (!\inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1010111000001100",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	dataa => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode41w[3]~0_combout\,
	datab => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode132w[3]~0_combout\,
	datac => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode4w[1]~0_combout\,
	datad => \inst6|inst|LPM_DECODE_component|auto_generated|w_anode162w[3]~4_combout\,
	combout => \inst6|inst6~0_combout\);

-- Location: LCCOMB_X1_Y11_N6
\inst6|inst6\ : cycloneiii_lcell_comb
-- Equation(s):
-- \inst6|inst6~combout\ = (\inst6|inst6~0_combout\) # ((!\inst6|inst1~3_combout\) # (!\inst6|inst1~4_combout\))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "1100111111111111",
	sum_lutc_input => "datac")
-- pragma translate_on
PORT MAP (
	datab => \inst6|inst6~0_combout\,
	datac => \inst6|inst1~4_combout\,
	datad => \inst6|inst1~3_combout\,
	combout => \inst6|inst6~combout\);

ww_D2 <= \D2~output_o\;

ww_D4 <= \D4~output_o\;

ww_D0 <= \D0~output_o\;

ww_D6 <= \D6~output_o\;

ww_D1 <= \D1~output_o\;

ww_D3 <= \D3~output_o\;

ww_D5 <= \D5~output_o\;
END structure;


