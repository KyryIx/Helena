-- frequency                   -- Hz
-- magneticInduction           -- G
-- currentDensity              -- A/mm2
-- averageCurrentDensity       -- A/mm2
-- weigthIron                  -- g
-- weightCopper                -- g
-- turnsAverageLength          -- cm
-- coilArea                    -- mm^2
-- windowAreaPerSectionTurns
-- ironLoss                    -- W
-- copperLoss                  -- W
-- totalLoss                   -- W
-- efficiency                  -- %
--
-- patternTransformerNumber    -- 0, 1 or 2
-- patternTransformerName      --
-- centerTap
-- compensationLossTransformer -- >= 0
--
-- powerIN                     -- W

-- voltageIN1                  -- V
-- currentIN1                  -- A
-- currentDensityIN1           -- A/mm^2
--
-- wireIDIN1
-- wireTypeIN1
-- wireAWGIN1
-- wireTurnsIN1                -- esp
-- wireDiameterIN1             -- mm
-- wireTurnPerCmIN1            -- esp/cm
-- wireAreaIN1                 -- mm^2
-- wireResistanceIN1           -- ohm/km
-- wireWeightIN1               -- kg/km
-- wireLengthIN1               -- m/kg
-- wireFrequencyIN1            -- kHz
-- wireMaterialIN1
--
-- voltageIN2                  -- V
-- currentIN2                  -- A
-- currentDensityIN2           -- A/mm^2
-- 
-- wireIDIN2
-- wireTypeIN2
-- wireAWGIN2
-- wireTurnsIN2                -- esp
-- wireDiameterIN2             -- mm
-- wireTurnPerCmIN2            -- esp/cm
-- wireAreaIN2                 -- mm^2
-- wireResistanceIN2           -- ohm/km
-- wireWeightIN2               -- kg/km
-- wireLengthIN2               -- m/kg
-- wireFrequencyIN2            -- kHz
-- wireMaterialIN2
--
-- powerOUT                    -- W
--
-- voltageOUT1                 -- V
-- currentOUT1                 -- A
-- currentDensityOUT1          -- A/mm^2
-- 
-- wireIDOUT1
-- wireTypeOUT1
-- wireAWGOUT1
-- wireTurnsOUT1               -- esp
-- wireDiameterOUT1            -- mm
-- wireTurnPerCmOUT1           -- esp/cm
-- wireAreaOUT1                -- mm^2
-- wireResistanceOUT1          -- ohm/km
-- wireWeightOUT1              -- kg/km
-- wireLengthOUT1              -- m/kg
-- wireFrequencyOUT1           -- kHz
-- wireMaterialOUT1
--
-- voltageOUT2                 -- V
-- currentOUT2                 -- A
-- currentDensityOUT2          -- A/mm^2
-- 
-- wireIDOUT2
-- wireTypeOUT2
-- wireAWGOUT2
-- wireTurnsOUT2               -- esp
-- wireDiameterOUT2            -- mm
-- wireTurnPerCmOUT2           -- esp/cm
-- wireAreaOUT2                -- mm^2
-- wireResistanceOUT2          -- ohm/km
-- wireWeightOUT2              -- kg/km
-- wireLengthOUT2              -- m/kg
-- wireFrequencyOUT2           -- kHz
-- wireMaterialOUT2
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
--
-- observation

CREATE TABLE IF NOT EXISTS transformer (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	frequency                   FLOAT,        -- Hz
	magneticInduction           FLOAT,        -- G
	currentDensity              FLOAT,        -- A/mm2
	averageCurrentDensity       FLOAT,        -- A/mm2
	weigthIron                  FLOAT,        -- g
	weightCopper                FLOAT,        -- g
	turnsAverageLength          FLOAT,        -- cm
	coilArea                    FLOAT,        -- mm^2
	windowAreaPerSectionTurns	FLOAT,        -- >= 0
	ironLoss                    FLOAT,        -- W
	copperLoss                  FLOAT,        -- W
	totalLoss                   FLOAT,        -- W
	efficiency                  FLOAT,        -- %
	
	patternTransformerNumber    INTEGER,      -- 0, 1 or 2
	patternTransformerName      VARCHAR(255)
	centerTap                   BOOLEAN       -- TRUE to center tap and FALSE otherwise
	compensationLossTransformer FLOAT,        -- >= 0
	
	powerIN                     FLOAT,        -- W
	
	voltageIN1                  FLOAT,        -- V
	currentIN1                  FLOAT,        -- A
	currentDensityIN1           FLOAT,        -- A/mm^2
	
	wireIDIN1                   INTEGER,
	wireTypeIN1                 VARCHAR(16),
	wireAWGIN1                  VARCHAR(5),
	wireTurnsIN1                INTEGER,      -- esp
	wireDiameterIN1             FLOAT,        -- mm
	wireTurnPerCmIN1            FLOAT,        -- esp/cm
	wireAreaIN1                 FLOAT,        -- mm^2
	wireResistanceIN1           FLOAT,        -- ohm/km
	wireWeightIN1               FLOAT,        -- kg/km
	wireLengthIN1               FLOAT,        -- m/kg
	wireFrequencyIN1            FLOAT,        -- kHz
	wireMaterialIN1             VARCHAR(64),
	
	voltageIN2                  FLOAT,        -- V
	currentIN2                  FLOAT,        -- A
	currentDensityIN2           FLOAT,        -- A/mm^2
	
	wireIDIN2                   INTEGER,
	wireTypeIN2                 VARCHAR(16),
	wireAWGIN2                  VARCHAR(5),
	wireTurnsIN2                INTEGER,      -- esp
	wireDiameterIN2             FLOAT,        -- mm
	wireTurnPerCmIN2            FLOAT,        -- esp/cm
	wireAreaIN2                 FLOAT,        -- mm^2
	wireResistanceIN2           FLOAT,        -- ohm/km
	wireWeightIN2               FLOAT,        -- kg/km
	wireLengthIN2               FLOAT,        -- m/kg
	wireFrequencyIN2            FLOAT,        -- kHz
	wireMaterialIN2             VARCHAR(64),
	
	powerOUT                    FLOAT,        -- W
	
	voltageOUT1                 FLOAT,        -- V
	currentOUT1                 FLOAT,        -- A
	currentDensityOUT1          FLOAT,        -- A/mm^2
	
	wireIDOUT1                  INTEGER,
	wireTypeOUT1                VARCHAR(16),
	wireAWGOUT1                 VARCHAR(5),
	wireTurnsOUT1               INTEGER,      -- esp
	wireDiameterOUT1            FLOAT,        -- mm
	wireTurnPerCmOUT1           FLOAT,        -- esp/cm
	wireAreaOUT1                FLOAT,        -- mm^2
	wireResistanceOUT1          FLOAT,        -- ohm/km
	wireWeightOUT1              FLOAT,        -- kg/km
	wireLengthOUT1              FLOAT,        -- m/kg
	wireFrequencyOUT1           FLOAT,        -- kHz
	wireMaterialOUT1            VARCHAR(64),
	
	voltageOUT2                 FLOAT,        -- V
	currentOUT2                 FLOAT,        -- A
	currentDensityOUT2          FLOAT,        -- A/mm^2
	
	wireIDOUT2                  INTEGER,
	wireTypeOUT2                VARCHAR(16),
	wireAWGOUT2                 VARCHAR(5),
	wireTurnsOUT2               INTEGER,      -- esp
	wireDiameterOUT2            FLOAT,        -- mm
	wireTurnPerCmOUT2           FLOAT,        -- esp/cm
	wireAreaOUT2                FLOAT,        -- mm^2
	wireResistanceOUT2          FLOAT,        -- ohm/km
	wireWeightOUT2              FLOAT,        -- kg/km
	wireLengthOUT2              FLOAT,        -- m/kg
	wireFrequencyOUT2           FLOAT,        -- kHz
	wireMaterialOUT2            VARCHAR(64),
	
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
	
	observation					TEXT
);

CREATE TABLE IF NOT EXISTS transformer( id INTEGER PRIMARY KEY AUTOINCREMENT, frequency FLOAT, magneticInduction FLOAT, currentDensity FLOAT, averageCurrentDensity FLOAT, weigthIron FLOAT, weightCopper FLOAT, turnsAverageLength FLOAT, coilArea FLOAT, windowAreaPerSectionTurns FLOAT, ironLoss FLOAT, copperLoss FLOAT, totalLoss FLOAT, efficiency FLOAT, patternTransformerNumber INTEGER, patternTransformerName VARCHAR(255), centerTap BOOLEAN, compensationLossTransformer FLOAT, powerIN FLOAT, voltageIN1 FLOAT, currentIN1 FLOAT, currentDensityIN1 FLOAT, wireIDIN1 INTEGER, wireTypeIN1 VARCHAR(16), wireAWGIN1 VARCHAR(5), wireTurnsIN1 INTEGER, wireDiameterIN1 FLOAT, wireTurnPerCmIN1 FLOAT, wireAreaIN1 FLOAT, wireResistanceIN1 FLOAT, wireWeightIN1 FLOAT, wireLengthIN1 FLOAT, wireFrequencyIN1 FLOAT, wireMaterialIN1 VARCHAR(64), voltageIN2 FLOAT, currentIN2 FLOAT, currentDensityIN2 FLOAT, wireIDIN2 INTEGER, wireTypeIN2 VARCHAR(16), wireAWGIN2 VARCHAR(5), wireTurnsIN2 INTEGER, wireDiameterIN2 FLOAT, wireTurnPerCmIN2 FLOAT, wireAreaIN2 FLOAT, wireResistanceIN2 FLOAT, wireWeightIN2 FLOAT, wireLengthIN2 FLOAT, wireFrequencyIN2 FLOAT, wireMaterialIN2 VARCHAR(64), powerOUT FLOAT, voltageOUT1 FLOAT, currentOUT1 FLOAT, currentDensityOUT1 FLOAT, wireIDOUT1 INTEGER, wireTypeOUT1 VARCHAR(16), wireAWGOUT1 VARCHAR(5), wireTurnsOUT1 INTEGER, wireDiameterOUT1 FLOAT, wireTurnPerCmOUT1 FLOAT, wireAreaOUT1 FLOAT, wireResistanceOUT1 FLOAT, wireWeightOUT1 FLOAT, wireLengthOUT1 FLOAT, wireFrequencyOUT1 FLOAT, wireMaterialOUT1 VARCHAR(64), voltageOUT2 FLOAT, currentOUT2 FLOAT, currentDensityOUT2 FLOAT, wireIDOUT2 INTEGER, wireTypeOUT2 VARCHAR(16), wireAWGOUT2 VARCHAR(5), wireTurnsOUT2 INTEGER, wireDiameterOUT2 FLOAT, wireTurnPerCmOUT2 FLOAT, wireAreaOUT2 FLOAT, wireResistanceOUT2 FLOAT, wireWeightOUT2 FLOAT, wireLengthOUT2 FLOAT, wireFrequencyOUT2 FLOAT, wireMaterialOUT2 VARCHAR(64), laminaID INTEGER, laminaType VARCHAR(64), laminaWidth FLOAT, laminaWindowArea FLOAT, laminaWeight FLOAT, laminaCompensation FLOAT, bobbinID INTEGER, bobbinType VARCHAR(64), bobbinCode VARCHAR(64), bobbinProvider VARCHAR(255), bobbinWidth FLOAT, bobbinLength FLOAT, bobbinHeight FLOAT, bobbinArea FLOAT, observation TEXT );

INSERT INTO transformer (
	frequency,
	magneticInduction,
	currentDensity,
	averageCurrentDensity,
	weigthIron,
	weightCopper,
	turnsAverageLength,
	coilArea,
	windowAreaPerSectionTurns,
	ironLoss,
	copperLoss,
	totalLoss,
	efficiency,
	
	patternTransformerNumber,
	patternTransformerName,
	centerTap,
	compensationLossTransformer,
	
	powerIN,
	
	voltageIN1,
	currentIN1,
	currentDensityIN1,
	
	wireIDIN1,
	wireTypeIN1,
	wireAWGIN1,
	wireTurnsIN1,
	wireDiameterIN1,
	wireTurnPerCmIN1,
	wireAreaIN1,
	wireResistanceIN1,
	wireWeightIN1,
	wireLengthIN1,
	wireFrequencyIN1,
	wireMaterialIN1,
	
	voltageIN2,
	currentIN2,
	currentDensityIN2,
	
	wireIDIN2,
	wireTypeIN2,
	wireAWGIN2,
	wireTurnsIN2,
	wireDiameterIN2,
	wireTurnPerCmIN2,
	wireAreaIN2,
	wireResistanceIN2,
	wireWeightIN2,
	wireLengthIN2,
	wireFrequencyIN2,
	wireMaterialIN2,
	
	powerOUT,
	
	voltageOUT1,
	currentOUT1,
	currentDensityOUT1,
	
	wireIDOUT1,
	wireTypeOUT1,
	wireAWGOUT1,
	wireTurnsOUT1,
	wireDiameterOUT1,
	wireTurnPerCmOUT1,
	wireAreaOUT1,
	wireResistanceOUT1,
	wireWeightOUT1,
	wireLengthOUT1,
	wireFrequencyOUT1,
	wireMaterialOUT1,
	
	voltageOUT2,
	currentOUT2,
	currentDensityOUT2,
	
	wireIDOUT2,
	wireTypeOUT2,
	wireAWGOUT2,
	wireTurnsOUT2,
	wireDiameterOUT2,
	wireTurnPerCmOUT2,
	wireAreaOUT2,
	wireResistanceOUT2,
	wireWeightOUT2,
	wireLengthOUT2,
	wireFrequencyOUT2,
	wireMaterialOUT2,
	
	laminaID,
	laminaType,
	laminaWidth,
	laminaWindowArea,
	laminaWeight,
	laminaCompensation,
	
	bobbinID,
	bobbinType,
	bobbinCode,
	bobbinProvider,
	bobbinWidth,
	bobbinLength,
	bobbinHeight,
	bobbinArea,
	
	observation
)
VALUES (
	60.0,			-- frequency
	11300.0,		-- magneticInduction
	3.0,			-- currentDensity
	2.64,			-- averageCurrentDensity
	4.32,			-- weigthIron
	1.09,			-- weightCopper
	26.05,			-- turnsAverageLength
	468.74,			-- coilArea
	3.0,			-- windowAreaPerSectionTurns
	8.56,			-- ironLoss
	18.40,			-- copperLoss
	26.96,			-- totalLoss
	91.76,			-- efficiency
	
	0,				-- patternTransformerNumber,
	'1 primary and 1 secondary with center tap',
	TRUE,			-- center tap,
	10.0,			-- compensationLossTransformer,
	
	330.0,			-- powerIN,
	
	120.0,			-- voltageIN1,
	2.75,			-- currentIN1,
	2.63,			-- currentDensityIN1,
	
	21,				-- wireIDIN1,
	'redondo',		-- wireTypeIN1,
	'17',			-- wireAWGIN1,
	236,			-- wireTurnsIN1,
	1.15,			-- wireDiameterIN1,
	0.0,			-- wireTurnPerCmIN1,
	1.04,			-- wireAreaIN1,
	0.0,			-- wireResistanceIN1,
	0.0,			-- wireWeightIN1,
	0.0,			-- wireLengthIN1,
	0.0,			-- wireFrequencyIN1,
	'cobre',		-- wireMaterialIN1,
	
	0.0,			-- voltageIN2,
	0.0,			-- currentIN2,
	0.0,			-- currentDensityIN2,
	
	0,				-- wireIDIN2,
	'redondo',		-- wireTypeIN2,
	'',				-- wireAWGIN2,
	0,				-- wireTurnsIN2,
	0.0,			-- wireDiameterIN2,
	0.0,			-- wireTurnPerCmIN2,
	0.0,			-- wireAreaIN2,
	0.0,			-- wireResistanceIN2,
	0.0,			-- wireWeightIN2,
	0.0,			-- wireLengthIN2,
	0.0,			-- wireFrequencyIN2,
	'',				-- wireMaterialIN2,
	
	30.0,			-- powerOUT,
	
	220.0,			-- voltageOUT1,
	1.36,			-- currentOUT1,
	2.63,			-- currentDensityOUT1,
	
	24,				-- wireIDOUT1,
	'redondo',		-- wireTypeOUT1,
	'20',			-- wireAWGOUT1,
	432,			-- wireTurnsOUT1,
	0.81,			-- wireDiameterOUT1,
	0.0,			-- wireTurnPerCmOUT1,
	0.52,			-- wireAreaOUT1,
	0.0,			-- wireResistanceOUT1,
	0.0,			-- wireWeightOUT1,
	0.0,			-- wireLengthOUT1,
	0.0,			-- wireFrequencyOUT1,
	'cobre',		-- wireMaterialOUT1,
	
	0.0,			-- voltageOUT2,
	0.0,			-- currentOUT2,
	0.0,			-- currentDensityOUT2,
	
	0,				-- wireIDOUT2,
	'redondo',		-- wireTypeOUT2,
	'',				-- wireAWGOUT2,
	0,				-- wireTurnsOUT2,
	0.0,			-- wireDiameterOUT2,
	0.0,			-- wireTurnPerCmOUT2,
	0.0,			-- wireAreaOUT2,
	0.0,			-- wireResistanceOUT2,
	0.0,			-- wireWeightOUT2,
	0.0,			-- wireLengthOUT2,
	0.0,			-- wireFrequencyOUT2,
	'cobre',		-- wireMaterialOUT2,
	
	7,				-- laminaID,
	'padrao',		-- laminaType,
	50.0,			-- laminaWidth,
	1880.0,			-- laminaWindowArea,
	1.05,			-- laminaWeight,
	10.0,			-- laminaCompensation,
	
	66,				-- bobbinID,
	'STSR',			-- bobbinType,
	'DR 03',		-- bobbinCode,
	'Dragão Plásticos',	-- bobbinProvider,
	50.0,				--bobbinWidth,
	41.0,				-- bobbinLength,
	75.0,				-- bobbinHeight,
	2050.0				-- bobbinArea,
	
	'Transformador em desenvolvimento' -- observation
)