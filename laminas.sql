--  width_lamina: espessura do nucleo central da lamina
--   area_lamina: secao da janela da lamina
-- weight_lamina: peso do nucleo em kilo por cm
--   type_lamina: tipo da lamina

CREATE TABLE laminas (
	id            INTEGER      PRIMARY KEY AUTOINCREMENT,
	width_lamina  DOUBLE,
	area_lamina   DOUBLE,
	weight_lamina DOUBLE,
	type_lamina   VARCHAR (64) 
);

INSERT INTO laminas (width_lamina, area_lamina, weight_lamina, type_lamina) VALUES
(15,  168, 0.095,  'simples' ),
(20,  300, 0.170,  'simples' ),
(25,  468, 0.273,  'simples' ),
(30,  675, 0.380,  'simples' ),
(35,  900, 0.516,  'simples' ),
(40, 1200, 0.674,  'simples' ),
(50, 1880, 1.053,  'simples' ),
(40, 2400, 1.000, 'especial' ),
(50, 3750, 1.580, 'especial' );

SELECT * FROM laminas WHERE (width_lamina > 42) AND (type_lamina LIKE 'especial') LIMIT 1;