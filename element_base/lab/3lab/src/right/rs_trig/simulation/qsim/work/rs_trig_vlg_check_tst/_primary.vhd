library verilog;
use verilog.vl_types.all;
entity rs_trig_vlg_check_tst is
    port(
        C               : in     vl_logic;
        CLRN            : in     vl_logic;
        PRN             : in     vl_logic;
        Q_rs            : in     vl_logic;
        R               : in     vl_logic;
        S               : in     vl_logic;
        X               : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end rs_trig_vlg_check_tst;
