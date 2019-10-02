﻿-- codigo -- codigo do carretel
-- largura  -- largura do nucleo central do carretel
-- comprimento -- comprimento do nucleo central do carretel
-- altura -- altura do nucleo central do carretel
-- tipo -- tipo do carretel
-- temperatura -- temperatura de trabalho do carretel
-- fornecedor -- nome do fornecedor do carretel

CREATE TABLE bobbins (
	id                  INTEGER      PRIMARY KEY AUTOINCREMENT,
	code_bobbin         VARCHAR(64),
	width_bobbin        DOUBLE,
	width_error_bobbin  DOUBLE,
	length_bobbin       DOUBLE,
	length_error_bobbin DOUBLE,
	height_bobbin       DOUBLE,
	height_error_bobbin DOUBLE,
	type_bobbin         VARCHAR(64),
	temperature_bobbin  DOUBLE,
	provider_bobbin     VARCHAR(255)
);

INSERT INTO bobbins (code_bobbin, width_bobbin, width_error_bobbin, length_bobbin, length_error_bobbin, height_bobbin, height_error_bobbin, type_bobbin, temperature_bobbin, provider_bobbin) VALUES
( 'DR 19', 25.4, 0.0,  60.0, 0.2,  38.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 46', 28.6, 0.0,  29.5, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 16', 28.6, 0.0,  33.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 47', 28.6, 0.0,  38.1, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 48', 28.6, 0.0,  42.1, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 15', 28.6, 0.0,  43.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 99', 28.6, 0.0,  45.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 38', 28.6, 0.0,  50.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 18', 28.6, 0.0,  60.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 131', 30.0, 0.0,  51.0, 0.2,  42.9, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 190', 28.0, 0.0,  29.5, 0.2,  42.9, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
('DR 182', 28.0, 0.0,  38.4, 0.2,  42.9, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
('DR 185', 32.0, 0.0,  22.5, 0.2,  48.0, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
('DR 186', 32.0, 0.0,  32.5, 0.2,  48.0, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
('DR 187', 32.0, 0.0,  40.3, 0.2,  48.0, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
('DR 188', 32.0, 0.0,  52.0, 0.2,  48.0, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
( 'DR 50', 32.0, 0.0,  22.3, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 33', 32.0, 0.0,  28.0, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 51', 32.0, 0.0,  32.3, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 52', 32.0, 0.0,  40.0, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 49', 32.0, 0.0,  45.3, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 53', 32.0, 0.0,  52.6, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 56', 32.0, 0.0,  55.1, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 54', 32.0, 0.0,  59.8, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 89', 32.0, 0.0,  66.5, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 55', 32.0, 0.0,  69.6, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 133', 32.0, 0.0,  38.0, 0.2,  48.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 06', 35.0, 0.0,  35.0, 0.2,  50.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 59', 35.0, 0.0,  50.6, 0.2,  52.5, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 191', 38.0, 0.0,  54.8, 0.2,  57.0, 0.0,   'PT', 140.0, 'Dragão Plásticos' ),
( 'DR 91', 38.0, 0.0,  32.0, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 60', 38.0, 0.0,  40.6, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 77', 38.0, 0.0,  45.7, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 62', 38.0, 0.0,  50.5, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 57', 38.0, 0.0,  55.3, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 58', 38.0, 0.0,  56.6, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 132', 38.0, 0.0,  58.0, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 61', 38.0, 0.0,  63.1, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 73', 38.0, 0.0,  66.1, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 78', 38.0, 0.0,  75.2, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 68', 38.0, 0.0,  80.4, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 79', 38.0, 0.0,  90.3, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 87', 38.0, 0.0,  94.0, 0.2,  57.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 81', 40.0, 0.0,  40.8, 0.5,  60.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 63', 40.0, 0.0,  44.5, 0.5,  60.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 64', 40.0, 0.0,  55.0, 0.5,  60.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 65', 40.0, 0.0,  65.3, 0.5,  60.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 171', 40.0, 0.0,  75.0, 0.5,  60.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 42', 42.0, 0.0,  44.0, 0.5,  63.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 67', 42.0, 0.0,  53.6, 0.5,  63.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 71', 42.0, 0.0,  70.6, 0.5,  63.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 72', 45.0, 0.0,  45.6, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 69', 45.0, 0.0,  56.0, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 170', 45.0, 0.0,  58.0, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 70', 45.0, 0.0,  70.3, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 85', 45.0, 0.0,  75.4, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
('DR 173', 45.0, 0.0,  64.0, 0.5,  64.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 83', 50.0, 0.0,  51.3, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 74', 50.0, 0.0,  60.3, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 76', 50.0, 0.0,  70.3, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 75', 50.0, 0.0,  80.0, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 86', 50.0, 0.0,  95.8, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 05', 50.0, 0.0,  31.0, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 07', 50.0, 0.0,  36.0, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 04', 50.0, 0.0,  46.0, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 03', 50.0, 0.0,  41.0, 0.5,  75.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 84', 60.8, 0.0,  75.4, 0.5,  90.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 80', 60.8, 0.0,  90.4, 0.5,  90.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' ),
( 'DR 93', 80.0, 0.0, 120.0, 0.5, 120.0, 0.0, 'STSR', 140.0, 'Dragão Plásticos' );