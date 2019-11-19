--           width_lamina: largura central da lamina em mm
--            area_lamina: area da janela da lamina em mm*mm
--          weight_lamina: peso do nucleo em kilo por cm
-- thicknesPercent_lamina: porcentagem da espessura do isolante em relacao a parte do ferro da lamina em porcentagem, exemplo: 10%
--            type_lamina: tipo da lamina

CREATE TABLE IF NOT EXISTS laminas (
	id                      INTEGER      PRIMARY KEY AUTOINCREMENT,
	width_lamina            DOUBLE,
	area_lamina             DOUBLE,
	weight_lamina           DOUBLE,
	thicknessPercent_lamina DOUBLE,
	type_lamina             VARCHAR (64) 
);

INSERT INTO laminas (width_lamina, area_lamina, weight_lamina, thicknessPercent_lamina, type_lamina) VALUES
(15,  168, 0.095, 10,    'padrao' ), -- 1
(20,  300, 0.170, 10,    'padrao' ), -- 2
(25,  468, 0.273, 10,    'padrao' ), -- 3
(30,  675, 0.380, 10,    'padrao' ), -- 4
(35,  900, 0.516, 10,    'padrao' ), -- 5
(40, 1200, 0.674, 10,    'padrao' ), -- 6
(50, 1880, 1.053, 10,    'padrao' ), -- 7
(40, 2400, 1.000, 10, 'compridas' ), -- 1
(50, 3750, 1.580, 10, 'compridas' ); -- 2

SELECT * FROM laminas WHERE (width_lamina > 42) AND (type_lamina LIKE 'especial') LIMIT 1;