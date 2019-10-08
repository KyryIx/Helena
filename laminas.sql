--  width_lamina: largura central da lamina em mm
--   area_lamina: area da janela da lamina em mm*mm
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
(15,  168, 0.095,  'padrao' ), -- 1
(20,  300, 0.170,  'padrao' ), -- 2
(25,  468, 0.273,  'padrao' ), -- 3
(30,  675, 0.380,  'padrao' ), -- 4
(35,  900, 0.516,  'padrao' ), -- 5
(40, 1200, 0.674,  'padrao' ), -- 6
(50, 1880, 1.053,  'padrao' ), -- 7
(40, 2400, 1.000, 'especial' ), -- 1
(50, 3750, 1.580, 'especial' ); -- 2

SELECT * FROM laminas WHERE (width_lamina > 42) AND (type_lamina LIKE 'especial') LIMIT 1;