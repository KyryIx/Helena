--        width_lamina: largura central da lamina em mm
--         area_lamina: area da janela da lamina em mm*mm
--       weight_lamina: peso do nucleo em kilo por cm
-- compensation_lamina: porcentagem da compensacao por espessura do isolante em relacao a parte do ferro da lamina em porcentagem como também sobre o empilhamento, exemplo: 10%
--         type_lamina: tipo da lamina

CREATE TABLE IF NOT EXISTS laminas (
	id                       INTEGER PRIMARY KEY AUTOINCREMENT,
	width_lamina             DOUBLE,
	window_area_lamina       DOUBLE,
	weight_lamina            DOUBLE,
	compensation_percent_lamina DOUBLE,
	type_lamina              VARCHAR (64),
	provider_lamina          VARCHAR(255)
);

INSERT INTO laminas (width_lamina, window_area_lamina, weight_lamina, compensation_percent_lamina, type_lamina, provider_lamina) VALUES
(15,  168, 0.095, 10,    'padrao', 'Acesita' ), -- 1
(20,  300, 0.170, 10,    'padrao', 'Acesita' ), -- 2
(25,  468, 0.273, 10,    'padrao', 'Acesita' ), -- 3
(30,  675, 0.380, 10,    'padrao', 'Acesita' ), -- 4
(35,  900, 0.516, 10,    'padrao', 'Acesita' ), -- 5
(40, 1200, 0.674, 10,    'padrao', 'Acesita' ), -- 6
(50, 1880, 1.053, 10,    'padrao', 'Acesita' ), -- 7
(40, 2400, 1.000, 10, 'compridas', 'Acesita' ), -- 1
(50, 3750, 1.580, 10, 'compridas', 'Acesita' ); -- 2