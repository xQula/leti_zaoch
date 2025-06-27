library verilog;
use verilog.vl_types.all;
entity Lab6_vlg_check_tst is
    port(
        D0              : in     vl_logic;
        D1              : in     vl_logic;
        D2              : in     vl_logic;
        D3              : in     vl_logic;
        D4              : in     vl_logic;
        D5              : in     vl_logic;
        D6              : in     vl_logic;
        Test            : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end Lab6_vlg_check_tst;
