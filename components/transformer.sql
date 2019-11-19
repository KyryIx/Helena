-- frequency                   -- Hz
-- magnetic_induction          -- G
-- current_density             -- A/mm2
-- average_current_density     -- A/mm2
-- weight_iron                 -- g
-- weight_copper               -- g
-- average_turn_length         -- cm
-- copper_area                 -- mm^2
-- window_area_per_section_copper
-- iron_loss                   -- W
-- copper_loss                 -- W
-- total_loss                  -- W
-- efficiency                  -- %
--
-- transformer_pattern_number  -- 0, 1 or 2
-- transformer_pattern_name    --
-- apply_center_tap
-- apply_transformer_loss_compensation
-- transformer_loss_compensation -- >= 0
--
-- input_power                 -- W
--
-- input_voltage_1             -- V
-- input_current_1             -- A
-- input_current_density_1     -- A/mm^2
--
-- input_wire_id_1
-- input_wire_type_1
-- input_wire_awg_1
-- input_wire_turns_1          -- esp
-- input_wire_diameter_1       -- mm
-- input_wire_turn_per_cm_1    -- esp/cm
-- input_wire_area_1           -- mm^2
-- input_wire_resistance_1     -- ohm/km
-- input_wire_weight_1         -- kg/km
-- input_wire_length_1         -- m/kg
-- input_wire_frequency_1      -- kHz
-- input_wire_material_1
-- input_wire_provider_1
--
-- input_voltage_2             -- V
-- input_current_2             -- A
-- input_current_density_2     -- A/mm^2
-- 
-- input_wire_id_2
-- input_wire_type_2
-- input_wire_awg_2
-- input_wire_turns_2          -- esp
-- input_wire_diameter_2       -- mm
-- input_wire_turn_per_cm_2    -- esp/cm
-- input_wire_area_2           -- mm^2
-- input_wire_resistance_2     -- ohm/km
-- input_wire_weight_2         -- kg/km
-- input_wire_length_2         -- m/kg
-- input_wire_frequency_2      -- kHz
-- input_wire_material_2
-- input_wire_provider_2
--
-- output_power                -- W
--
-- output_voltage_1            -- V
-- output_current_1            -- A
-- output_current_density_1    -- A/mm^2
-- 
-- output_wire_id_1
-- output_wire_type_1
-- output_wire_awg_1
-- output_wire_turns_1         -- esp
-- output_wire_diameter_1      -- mm
-- output_wire_turn_per_cm_1   -- esp/cm
-- output_wire_area_1          -- mm^2
-- output_wire_resistance_1    -- ohm/km
-- output_wire_weight_1        -- kg/km
-- output_wire_length_1        -- m/kg
-- output_wire_frequency_1     -- kHz
-- output_wire_material_1
-- output_wire_provider_1
--
-- output_voltage_2            -- V
-- output_current_2            -- A
-- output_current_density_2    -- A/mm^2
-- 
-- output_wire_id_2
-- output_wire_type_2
-- output_wire_awg_2
-- output_wire_turns_2         -- esp
-- output_wire_diameter_2      -- mm
-- output_wire_turn_per_cm_2   -- esp/cm
-- output_wire_area_2          -- mm^2
-- output_wire_resistance_2    -- ohm/km
-- output_wire_weight_2        -- kg/km
-- output_wire_length_2        -- m/kg
-- output_wire_frequency_2     -- kHz
-- output_wire_material_2
-- OUTput_wire_provider_2
--
-- lamina_id
-- lamina_type
-- lamina_provider
-- lamina_width                -- mm
-- lamina_window_area          -- mm^2
-- lamina_weight               -- kg/cm
-- lamina_compensation_state
-- lamina_compensation_value   -- >= 0
-- 
-- bobbin_id
-- bobbin_type
-- bobbin_code
-- bobbin_provider
-- bobbin_width                -- mm
-- bobbin_length               -- mm
-- bobbin_height               -- mm
--
-- observation

CREATE TABLE IF NOT EXISTS transformer (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	frequency                   FLOAT,        -- Hz
	magnetic_induction          FLOAT,        -- G
	current_density             FLOAT,        -- A/mm2
	average_current_density     FLOAT,        -- A/mm2
	weight_iron                 FLOAT,        -- g
	weight_copper               FLOAT,        -- g
	average_turn_length         FLOAT,        -- cm
	copper_area                 FLOAT,        -- mm^2
	window_area_per_section_copper FLOAT,     -- >= 0
	iron_loss                   FLOAT,        -- W
	copper_loss                 FLOAT,        -- W
	total_loss                  FLOAT,        -- W
	efficiency                  FLOAT,        -- %
	
	transformer_pattern_number  INTEGER,      -- 0, 1 or 2
	transformer_pattern_name    VARCHAR(255),
	apply_center_tap            BOOLEAN,      -- TRUE to center tap and FALSE otherwise
	apply_transformer_loss_compensation BOOLEAN,
	transformer_loss_compensation FLOAT,      -- >= 0
	
	input_power                 FLOAT,        -- W
	
	input_voltage_1             FLOAT,        -- V
	input_current_1             FLOAT,        -- A
	input_current_density_1     FLOAT,        -- A/mm^2
	
	input_wire_id_1             INTEGER,
	input_wire_type_1           VARCHAR(16),
	input_wire_awg_1            VARCHAR(5),
	input_wire_turns_1          INTEGER,      -- esp
	input_wire_diameter_1       FLOAT,        -- mm
	input_wire_turn_per_cm_1    FLOAT,        -- esp/cm
	input_wire_area_1           FLOAT,        -- mm^2
	input_wire_resistance_1     FLOAT,        -- ohm/km
	input_wire_weight_1         FLOAT,        -- kg/km
	input_wire_length_1         FLOAT,        -- m/kg
	input_wire_frequency_1      FLOAT,        -- kHz
	input_wire_material_1       VARCHAR(64),
	input_wire_provider_1		VARCHAR(255),
	
	input_voltage_2             FLOAT,        -- V
	input_current_2             FLOAT,        -- A
	input_current_density_2     FLOAT,        -- A/mm^2
	
	input_wire_id_2             INTEGER,
	input_wire_type_2           VARCHAR(16),
	input_wire_awg_2            VARCHAR(5),
	input_wire_turns_2          INTEGER,      -- esp
	input_wire_diameter_2       FLOAT,        -- mm
	input_wire_turn_per_cm_2    FLOAT,        -- esp/cm
	input_wire_area_2           FLOAT,        -- mm^2
	input_wire_resistance_2     FLOAT,        -- ohm/km
	input_wire_weight_2         FLOAT,        -- kg/km
	input_wire_length_2         FLOAT,        -- m/kg
	input_wire_frequency_2      FLOAT,        -- kHz
	input_wire_material_2       VARCHAR(64),
	input_wire_provider_2		VARCHAR(255),
	
	output_power                FLOAT,        -- W
	
	output_voltage_1            FLOAT,        -- V
	output_current_1            FLOAT,        -- A
	output_current_density_1    FLOAT,        -- A/mm^2
	
	output_wire_id_1            INTEGER,
	output_wire_type_1          VARCHAR(16),
	output_wire_awg_1           VARCHAR(5),
	output_wire_turns_1         INTEGER,      -- esp
	output_wire_diameter_1      FLOAT,        -- mm
	output_wire_turn_per_cm_1   FLOAT,        -- esp/cm
	output_wire_area_1          FLOAT,        -- mm^2
	output_wire_resistance_1    FLOAT,        -- ohm/km
	output_wire_weight_1        FLOAT,        -- kg/km
	output_wire_length_1        FLOAT,        -- m/kg
	output_wire_frequency_1     FLOAT,        -- kHz
	output_wire_material_1      VARCHAR(64),
	output_wire_provider_1		VARCHAR(255),
	
	output_voltage_2            FLOAT,        -- V
	output_current_2            FLOAT,        -- A
	output_current_density_2    FLOAT,        -- A/mm^2
	
	output_wire_id_2            INTEGER,
	output_wire_type_2          VARCHAR(16),
	output_wire_awg_2           VARCHAR(5),
	output_wire_turns_2         INTEGER,      -- esp
	output_wire_diameter_2      FLOAT,        -- mm
	output_wire_turn_per_cm_2   FLOAT,        -- esp/cm
	output_wire_area_2          FLOAT,        -- mm^2
	output_wire_resistance_2    FLOAT,        -- ohm/km
	output_wire_weight_2        FLOAT,        -- kg/km
	output_wire_length_2        FLOAT,        -- m/kg
	output_wire_frequency_2     FLOAT,        -- kHz
	output_wire_material_2      VARCHAR(64),
	output_wire_provider_2		VARCHAR(255),
	
	lamina_id                   INTEGER,
	lamina_type                 VARCHAR(64),
	lamina_provider				VARCHAR(255),
	lamina_width                FLOAT,        -- mm
	lamina_window_area          FLOAT,        -- mm^2
	lamina_weight               FLOAT,        -- kg/cm
	lamina_compensation_state   BOOLEAN,
	lamina_compensation_value   FLOAT,        -- >= 0
	
	bobbin_id                   INTEGER,
	bobbin_type                 VARCHAR(64),
	bobbin_code                 VARCHAR(64),
	bobbin_provider             VARCHAR(255),
	bobbin_width                FLOAT,        -- mm
	bobbin_length               FLOAT,        -- mm
	bobbin_height               FLOAT,        -- mm
	
	observation					TEXT
);

CREATE TABLE IF NOT EXISTS transformer ( id INTEGER PRIMARY KEY AUTOINCREMENT, frequency FLOAT, magnetic_induction FLOAT, current_density FLOAT, average_current_density FLOAT, weight_iron FLOAT, weight_copper FLOAT, average_turn_length FLOAT, copper_area FLOAT, window_area_per_section_copper FLOAT, iron_loss FLOAT, copper_loss FLOAT, total_loss FLOAT, efficiency FLOAT, transformer_pattern_number INTEGER, transformer_pattern_name VARCHAR(255), apply_center_tap BOOLEAN, apply_transformer_loss_compensation BOOLEAN, transformer_loss_compensation FLOAT, input_power FLOAT, input_voltage_1 FLOAT, input_current_1 FLOAT, input_current_density_1 FLOAT, input_wire_id_1 INTEGER, input_wire_type_1 VARCHAR(16), input_wire_awg_1 VARCHAR(5), input_wire_turns_1 INTEGER, input_wire_diameter_1 FLOAT, input_wire_turn_per_cm_1 FLOAT, input_wire_area_1 FLOAT, input_wire_resistance_1 FLOAT, input_wire_weight_1 FLOAT, input_wire_length_1 FLOAT, input_wire_frequency_1 FLOAT, input_wire_material_1 VARCHAR(64), input_wire_provider_1 VARCHAR(255), input_voltage_2 FLOAT, input_current_2 FLOAT, input_current_density_2 FLOAT, input_wire_id_2 INTEGER, input_wire_type_2 VARCHAR(16), input_wire_awg_2 VARCHAR(5), input_wire_turns_2 INTEGER, input_wire_diameter_2 FLOAT, input_wire_turn_per_cm_2 FLOAT, input_wire_area_2 FLOAT, input_wire_resistance_2 FLOAT, input_wire_weight_2 FLOAT, input_wire_length_2 FLOAT, input_wire_frequency_2 FLOAT, input_wire_material_2 VARCHAR(64), input_wire_provider_2 VARCHAR(255), output_power FLOAT, output_voltage_1 FLOAT, output_current_1 FLOAT, output_current_density_1 FLOAT, output_wire_id_1 INTEGER, output_wire_type_1 VARCHAR(16), output_wire_awg_1 VARCHAR(5), output_wire_turns_1 INTEGER, output_wire_diameter_1 FLOAT, output_wire_turn_per_cm_1 FLOAT, output_wire_area_1 FLOAT, output_wire_resistance_1 FLOAT, output_wire_weight_1 FLOAT, output_wire_length_1 FLOAT, output_wire_frequency_1 FLOAT, output_wire_material_1 VARCHAR(64), output_wire_provider_1 VARCHAR(255), output_voltage_2 FLOAT, output_current_2 FLOAT, output_current_density_2 FLOAT, output_wire_id_2 INTEGER, output_wire_type_2 VARCHAR(16), output_wire_awg_2 VARCHAR(5), output_wire_turns_2 INTEGER, output_wire_diameter_2 FLOAT, output_wire_turn_per_cm_2 FLOAT, output_wire_area_2 FLOAT, output_wire_resistance_2 FLOAT, output_wire_weight_2 FLOAT, output_wire_length_2 FLOAT, output_wire_frequency_2 FLOAT, output_wire_material_2 VARCHAR(64), output_wire_provider_2 VARCHAR(255), lamina_id INTEGER, lamina_type VARCHAR(64), lamina_provider VARCHAR(255), lamina_width FLOAT, lamina_window_area FLOAT, lamina_weight FLOAT, lamina_compensation_state BOOLEAN, lamina_compensation_value FLOAT, bobbin_id INTEGER, bobbin_type VARCHAR(64), bobbin_code VARCHAR(64), bobbin_provider VARCHAR(255), bobbin_width FLOAT, bobbin_length FLOAT, bobbin_height FLOAT, observation TEXT );

INSERT INTO transformer (
	frequency,
	magnetic_induction,
	current_density,
	average_current_density,
	weight_iron,
	weight_copper,
	average_turn_length,
	copper_area,
	window_area_per_section_copper,
	iron_loss,
	copper_loss,
	total_loss,
	efficiency,
	
	transformer_pattern_number,
	transformer_pattern_name,
	apply_center_tap,
	apply_transformer_loss_compensation,
	transformer_loss_compensation,
	
	input_power,
	
	input_voltage_1,
	input_current_1,
	input_current_density_1,
	
	input_wire_id_1,
	input_wire_type_1,
	input_wire_awg_1,
	input_wire_turns_1,
	input_wire_diameter_1,
	input_wire_turn_per_cm_1,
	input_wire_area_1,
	input_wire_resistance_1,
	input_wire_weight_1,
	input_wire_length_1,
	input_wire_frequency_1,
	input_wire_material_1,
	input_wire_provider_1,
	
	input_voltage_2,
	input_current_2,
	input_current_density_2,
	
	input_wire_id_2,
	input_wire_type_2,
	input_wire_awg_2,
	input_wire_turns_2,
	input_wire_diameter_2,
	input_wire_turn_per_cm_2,
	input_wire_area_2,
	input_wire_resistance_2,
	input_wire_weight_2,
	input_wire_length_2,
	input_wire_frequency_2,
	input_wire_material_2,
	input_wire_provider_2,
	
	output_power,
	
	output_voltage_1,
	output_current_1,
	output_current_density_1,
	
	output_wire_id_1,
	output_wire_type_1,
	output_wire_awg_1,
	output_wire_turns_1,
	output_wire_diameter_1,
	output_wire_turn_per_cm_1,
	output_wire_area_1,
	output_wire_resistance_1,
	output_wire_weight_1,
	output_wire_length_1,
	output_wire_frequency_1,
	output_wire_material_1,
	output_wire_provider_1,
	
	output_voltage_2,
	output_current_2,
	output_current_density_2,
	
	output_wire_id_2,
	output_wire_type_2,
	output_wire_awg_2,
	output_wire_turns_2,
	output_wire_diameter_2,
	output_wire_turn_per_cm_2,
	output_wire_area_2,
	output_wire_resistance_2,
	output_wire_weight_2,
	output_wire_length_2,
	output_wire_frequency_2,
	output_wire_material_2,
	output_wire_provider_2,
	
	lamina_id,
	lamina_type,
	lamina_provider,
	lamina_width,
	lamina_window_area,
	lamina_weight,
	lamina_compensation_state,
	lamina_Compensation_value,
	
	bobbin_id,
	bobbin_type,
	bobbin_code,
	bobbin_provider,
	bobbin_width,
	bobbin_length,
	bobbin_height,
	
	observation 
)
VALUES (
	60.0,			-- frequency
	11300.0,		-- magnetic_induction
	3.0,			-- current_density
	2.64,			-- average_current_density
	4.32,			-- weight_iron
	1.09,			-- weight_copper
	26.05,			-- average_turn_length
	468.74,			-- copper_area
	3.0,			-- window_area_per_section_copper
	8.56,			-- iron_loss
	18.40,			-- copper_loss
	26.96,			-- total_loss
	91.76,			-- efficiency
	
	0,				-- transformer_pattern_number,
	'1 primary and 1 secondary with center tap', -- transformer_pattern_name
	TRUE,			-- apply_center_tap,
	TRUE,			-- apply_transformer_loss_compensation,
	10.0,			-- transformer_loss_compensation,
	
	330.0,			-- input_power,
	
	120.0,			-- input_voltage_1,
	2.75,			-- input_current_1,
	2.63,			-- input_current_density_1,
	
	21,				-- input_wire_id_1,
	'redondo',		-- input_wire_type_1,
	'17',			-- input_wire_awg_1,
	236,			-- input_wire_turns_1,
	1.15,			-- input_wire_diameter_1,
	0.0,			-- input_wire_turn_per_cm_1,
	1.04,			-- input_wire_area_1,
	0.0,			-- input_wire_resistance_1,
	0.0,			-- input_wire_weight_1,
	0.0,			-- input_wire_length_1,
	0.0,			-- input_wire_frequency_1,
	'cobre',		-- input_wire_material_1,
	'-',			-- input_wire_provider_1,
	
	0.0,			-- input_voltage_2,
	0.0,			-- input_current_2,
	0.0,			-- input_current_density_2,
	
	0,				-- input_wire_id_2,
	'redondo',		-- input_wire_type_2,
	'',				-- input_wire_awg_2,
	0,				-- input_wire_turns_2,
	0.0,			-- input_wire_diameter_2,
	0.0,			-- input_wire_turn_per_cm_2,
	0.0,			-- input_wire_area_2,
	0.0,			-- input_wire_resistance_2,
	0.0,			-- input_wire_weight_2,
	0.0,			-- input_wire_length_2,
	0.0,			-- input_wire_frequency_2,
	'',				-- input_wire_material_2,
	'-',			-- input_wire_provider_2,

	30.0,			-- output_power,
	
	220.0,			-- output_voltage_1,
	1.36,			-- output_current_1,
	2.63,			-- output_current_density_1,
	
	24,				-- output_wire_id_1,
	'redondo',		-- output_wire_type_1,
	'20',			-- output_wire_awg_1,
	432,			-- output_wire_turns_1,
	0.81,			-- output_wire_diameter_1,
	0.0,			-- output_wire_turn_per_cm_1,
	0.52,			-- output_wire_area_1,
	0.0,			-- output_wire_resistance_1,
	0.0,			-- output_wire_weight_1,
	0.0,			-- output_wire_length_1,
	0.0,			-- output_wire_frequency_1,
	'cobre',		-- output_wire_material_1,
	'-',			-- output_wire_provider_1,
	
	0.0,			-- output_voltage_2,
	0.0,			-- output_current_2,
	0.0,			-- output_current_density_2,
	
	0,				-- output_wire_id_2,
	'redondo',		-- output_wire_type_2,
	'',				-- output_wire_awg_2,
	0,				-- output_wire_turns_2,
	0.0,			-- output_wire_diameter_2,
	0.0,			-- output_wire_turn_per_cm_2,
	0.0,			-- output_wire_area_2,
	0.0,			-- output_wire_resistance_2,
	0.0,			-- output_wire_weight_2,
	0.0,			-- output_wire_length_2,
	0.0,			-- output_wire_frequency_2,
	'cobre',		-- output_wire_material_2,
	'-',			-- output_wire_provider_2,
	
	7,				-- lamina_id,
	'padrao',		-- lamina_type,
	'-',			-- lamina_provider
	50.0,			-- lamina_width,
	1880.0,			-- lamina_window_area,
	1.05,			-- lamina_weight,
	TRUE,			-- lamina_compensation_state,
	10.0,			-- lamina_Compensation_value,
	
	66,				-- bobbin_id,
	'STSR',			-- bobbin_type,
	'DR 03',		-- bobbin_code,
	'Dragão Plásticos',	-- bobbin_provider,
	50.0,				--bobbin_width,
	41.0,				-- bobbin_length,
	75.0,				-- bobbin_height,
	
	'Transformador em desenvolvimento' -- observation
);