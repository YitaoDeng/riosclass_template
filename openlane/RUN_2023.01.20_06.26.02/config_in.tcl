#######################################################################################################
set ::env(PDK) "sky130A"
set ::env(STD_CELL_LIBRARY) "sky130_fd_sc_hd"
set script_dir $::env(DESIGN_DIR)


set ::env(DESIGN_NAME) hehe

########################################################################################################

# User Configurations
set ::env(DESIGN_IS_CORE) 0
## Clock configurations
set ::env(CLOCK_PORT) "clk"
set ::env(CLOCK_PERIOD) "12.5"
#set ::env(FP_PIN_ORDER_CFG) "$proj_dir/pin.cfg"
set ::env(FP_SIZING) "absolute"
set ::env(DIE_AREA) "0 0 1950 1950"
set ::env(PL_TARGET_DENSITY) 0.34
set ::env(FP_PDN_CORE_RING) 0
#set ::env(SYNTH_USE_PG_PINS_DEFINES) "USE_POWER_PINS"
set ::env(SYNTH_DEFINES) [list SYNTHESIS ]
set ::env(VDD_NETS) [list {vccd1}]
 set ::env(GND_NETS) [list {vssd1}]
set ::env(VDD_PIN)  [list {vccd1}]
set ::env(GND_PIN)  [list {vssd1}]
########################################################################################################
## Source Verilog Files
set ::env(VERILOG_FILES) "\
    $script_dir/src/cache/cacheblock/*.v \
    $script_dir/src/core_empty/lsu/*.v \
    $script_dir/src/core_empty/units/*.v \
    $script_dir/src/core_empty/pipeline/*.v \
    $script_dir/src/core_empty/core_empty.v \
    $script_dir/src/cache/*.v \
    $script_dir/src/*.v \
    $script_dir/src/params.vh"
########################################################################################################
set ::env(RT_MAX_LAYER) {met4}
set ::env(DIODE_INSERTION_STRATEGY) 3
set ::env(FILL_INSERTION) 1
set ::env(TAP_DECAP_INSERTION) 1
set ::env(QUIT_ON_LVS_ERROR) "0"
set ::env(QUIT_ON_MAGIC_DRC) "0"
set ::env(QUIT_ON_NEGATIVE_WNS) "0"
set ::env(QUIT_ON_SLEW_VIOLATIONS) "0"
set ::env(QUIT_ON_TIMING_VIOLATIONS) "0"
set ::env(SYNTH_MAX_FANOUT) 20
set ::env(ROUTING_CORES) "58"
set ::env(RUN_CVC) 0
