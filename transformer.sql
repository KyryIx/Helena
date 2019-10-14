-- frequency                   -- Hz
-- magneticInduction           -- G
-- currentDensity              -- A/mm2
-- averageCurrentDensity          -- A/mm2
-- weigthIron                  -- g
-- weightCopper                -- g
-- turnsAverageLength          -- cm
-- coilArea                    -- mm^2
-- ironLoss                    -- W
-- copperLoss                  -- W
-- totalLoss                   -- W
-- efficiency                  -- %
-- 
-- patternTransformer          -- 0, 1 or 2
-- compensationLossTransformer -- >= 0
-- 
-- voltageIN                   -- V
-- powerIN                     -- W
-- currentIN                   -- A
-- currentDensityIN            -- A/mm^2
-- 
-- wireIDIN                    
-- wireAWGIN                   
-- wireTurnsIN                 -- esp
-- wireDiameterIN              -- mm
-- wireTurnPerCmIN             -- esp/cm
-- wireAreaIN                  -- mm^2
-- wireResistanceIN            -- ohm/km
-- wireWeightIN                -- kg/km
-- wireLengthIN                -- m/kg
-- wireFrequencyIN             -- kHz
-- wireMaterialIN
-- 
-- voltageOUT                  -- V
-- powerOUT                    -- W
-- currentOUT                  -- A
-- currentDensityOUT           -- A/mm^2
-- 
-- wireIDOUT                   
-- wireAWGOUT                  
-- wireTurnsOUT                -- esp
-- wireDiameterOUT             -- mm
-- wireTurnPerCmOUT            -- esp/cm
-- wireAreaOUT                 -- mm^2
-- wireResistanceOUT           -- ohm/km
-- wireWeightOUT               -- kg/km
-- wireLengthOUT               -- m/kg
-- wireFrequencyOUT            -- kHz
-- wireMaterialOUT
-- 
-- laminaID                    
-- laminaType                  
-- laminaWidth                 -- mm
-- laminaWindowArea            -- mm^2
-- laminaWeight                -- kg/cm
-- laminaCompensation          -- >= 0
-- 
-- bobbinID                    
-- bobbinType                  
-- bobbinCode                  
-- bobbinProvider              
-- bobbinWidth                 -- mm
-- bobbinLength                -- mm
-- bobbinHeight                -- mm
-- bobbinArea                  -- mm^2
-- bobbinVolume                -- mm^3

-- stateProject                -- automatic, manual, ...

CREATE TABLE transformer (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	frequency                   FLOAT,        -- Hz
	magneticInduction           FLOAT,        -- G
	currentDensity              FLOAT,        -- A/mm2
	averageCurrentDensity       FLOAT,        -- A/mm2
	weigthIron                  FLOAT,        -- g
	weightCopper                FLOAT,        -- g
	turnsAverageLength          FLOAT,      -- cm
	coilArea                    FLOAT,        -- mm^2
	ironLoss                    FLOAT,        -- W
	copperLoss                  FLOAT,        -- W
	totalLoss                   FLOAT,        -- W
	efficiency                  FLOAT,        -- %
	
	patternTransformer          INTEGER,      -- 0, 1 or 2
	compensationLossTransformer FLOAT,        -- >= 0
	
	voltageIN                   FLOAT,        -- V
	powerIN                     FLOAT,        -- W
	currentIN                   FLOAT,        -- A
	currentDensityIN            FLOAT,        -- A/mm^2
	
	wireIDIN                    INTEGER,
	wireAWGIN                   VARCHAR(5),
	wireTurnsIN                 INTEGER,      -- esp
	wireDiameterIN              FLOAT,        -- mm
	wireTurnPerCmIN             FLOAT,        -- esp/cm
	wireAreaIN                  FLOAT,        -- mm^2
	wireResistanceIN            FLOAT,        -- ohm/km
	wireWeightIN                FLOAT,        -- kg/km
	wireLengthIN                FLOAT,        -- m/kg
	wireFrequencyIN             FLOAT,        -- kHz
	wireMaterialIN              VARCHAR(64),
	
	voltageOUT                  FLOAT,        -- V
	powerOUT                    FLOAT,        -- W
	currentOUT                  FLOAT,        -- A
	currentDensityOUT           FLOAT,        -- A/mm^2
	
	wireIDOUT                   INTEGER,
	wireAWGOUT                  VARCHAR(5),
	wireTurnsOUT                INTEGER,      -- esp
	wireDiameterOUT             FLOAT,        -- mm
	wireTurnPerCmOUT            FLOAT,        -- esp/cm
	wireAreaOUT                 FLOAT,        -- mm^2
	wireResistanceOUT           FLOAT,        -- ohm/km
	wireWeightOUT               FLOAT,        -- kg/km
	wireLengthOUT               FLOAT,        -- m/kg
	wireFrequencyOUT            FLOAT,        -- kHz
	wireMaterialOUT             VARCHAR(64),
	
	laminaID                    INTEGER,
	laminaType                  VARCHAR(64),
	laminaWidth                 FLOAT,        -- mm
	laminaWindowArea            FLOAT,        -- mm^2
	laminaWeight                FLOAT,        -- kg/cm
	laminaCompensation          FLOAT,        -- >= 0
	
	bobbinID                    INTEGER,
	bobbinType                  VARCHAR(64),
	bobbinCode                  VARCHAR(64),
	bobbinProvider              VARCHAR(255),
	bobbinWidth                 FLOAT,        -- mm
	bobbinLength                FLOAT,        -- mm
	bobbinHeight                FLOAT,        -- mm
	bobbinArea                  FLOAT,        -- mm^2
	bobbinVolume                FLOAT,        -- mm^3
	
	stateProject                VARCHAR(64)   -- automatic, manual, ...
);