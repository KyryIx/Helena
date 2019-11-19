--                       tipo: tipo do fio, se redondo ou retangular (fita)
--                        awg: numero AWG
--                   diametro: iametro dado em mm
--               espirasPerCm: espiras por cm
--                       area: area da secao transversal em mm^2
--                resistencia: resistencia em ohm/km
--                       peso: peso em kg/km
--                comprimento: comprimento em m/kg
-- (correnteMaxima/densidade): corrente maxima por densidade de corrente
--                 frequencia: frequencia maxima em kHz
--                   material: material do fio
			
CREATE TABLE IF NOT EXISTS wires (
	id                        INTEGER PRIMARY KEY AUTOINCREMENT,
	type_wire                 VARCHAR(64),
	awg_wire                  VARCHAR(6),
	diameter_wire             DOUBLE,
	turnsPerCm_wire           DOUBLE,
	area_wire                 DOUBLE,
	resistance_wire           DOUBLE,
	weight_wire               DOUBLE,
	length_wire               DOUBLE,
	currentMaxPerDensity_wire VARCHAR(255),
	frequency_wire            DOUBLE,
	material_wire             VARCHAR(64),
	provider_wire             VARCHAR(255)
);

INSERT INTO wires (type_wire, awg_wire, diameter_wire, turnsPerCm_wire, area_wire, resistance_wire, weight_wire, length_wire, currentMaxPerDensity_wire, frequency_wire, material_wire, provider_wire) VALUES
( 'redondo', '0000', 11.68400,   0.856, 107.21900,    0.160, 960.70000,     1.0409, '2.5, 268.04800, 3.0, 321.65800, 6.0, 643.3150',    0.128, 'cobre', '-' ),
( 'redondo',  '000', 10.40490,   0.961,  85.02900,    0.202, 761.90000,     1.3126, '2.5, 212.57300, 3.0, 255.08800, 6.0, 510.1760',    0.161, 'cobre', '-' ),
( 'redondo',   '00',  9.26590,   1.079,  67.43200,    0.255, 604.20000,     1.6551, '2.5, 168.57900, 3.0, 202.29500, 6.0, 404.5900',    0.203, 'cobre', '-' ),
( 'redondo',    '0',  8.25150,   1.212,  53.47600,    0.322, 479.10000,     2.0870, '2.5, 133.69000, 3.0, 160.42800, 6.0, 320.8570',    0.256, 'cobre', '-' ),
( 'redondo',    '1',  7.34820,   1.361,  42.40900,    0.406, 380.00000,     2.6317, '2.5, 106.02200, 3.0, 127.22600, 6.0, 254.4530',    0.323, 'cobre', '-' ),
( 'redondo',    '2',  6.54380,   1.528,  33.63200,    0.511, 301.30000,     3.3185, '2.5,  84.08000, 3.0, 100.89600, 6.0, 201.7920',    0.407, 'cobre', '-' ),
( 'redondo',    '3',  5.82750,   1.716,  26.67100,    0.645, 239.00000,     4.1845, '2.5,  66.67900, 3.0,  80.01400, 6.0, 160.0290',    0.513, 'cobre', '-' ),
( 'redondo',    '4',  5.18950,   1.927,  21.15200,    0.813, 189.50000,     5.2765, '2.5,  52.87900, 3.0,  63.45500, 6.0, 126.9100',    0.647, 'cobre', '-' ),
( 'redondo',    '5',  4.62140,   2.164,  16.77400,    1.025, 150.30000,     6.6535, '2.5,  41.93500, 3.0,  50.32200, 6.0, 100.6450',    0.816, 'cobre', '-' ),
( 'redondo',    '6',  4.11550,   2.430,  13.30300,    1.293, 119.20000,     8.3899, '2.5,  33.25600, 3.0,  39.90800, 6.0,  79.8150',    1.029, 'cobre', '-' ),
( 'redondo',    '7',  3.66500,   2.729,  10.54900,    1.630,  94.52000,    10.5790, '2.5,  26.37400, 3.0,  31.64800, 6.0,  63.2970',    1.297, 'cobre', '-' ),
( 'redondo',    '8',  3.26380,   3.064,   8.36600,    2.056,  74.96000,    13.3400, '2.5,  20.91500, 3.0,  25.09800, 6.0,  50.1970',    1.636, 'cobre', '-' ),
( 'redondo',    '9',  2.90650,   3.441,   6.63500,    2.592,  59.45000,    16.8220, '2.5,  16.58700, 3.0,  19.90400, 6.0,  39.8080',    2.063, 'cobre', '-' ),
( 'redondo',   '10',  2.58830,   3.864,   5.26200,    3.269,  47.14000,    21.2120, '2.5,  13.15400, 3.0,  15.78500, 6.0,  31.5700',    2.601, 'cobre', '-' ),
( 'redondo',   '11',  2.30500,   4.338,   4.17300,    4.122,  37.39000,    26.7470, '2.5,  10.43200, 3.0,  12.51800, 6.0,  25.0360',    3.280, 'cobre', '-' ),
( 'redondo',   '12',  2.05260,   4.872,   3.30900,    5.198,  29.65000,    33.7270, '2.5,   8.27300, 3.0,   9.92700, 6.0,  19.8550',    4.136, 'cobre', '-' ),
( 'redondo',   '13',  1.82790,   5.471,   2.62400,    6.554,  23.51000,    42.5290, '2.5,   6.56100, 3.0,   7.87300, 6.0,  15.7460',    5.216, 'cobre', '-' ),
( 'redondo',   '14',  1.62780,   6.143,   2.08100,    8.265,  18.65000,    53.6280, '2.5,   5.20300, 3.0,   6.24300, 6.0,  12.4870',    6.577, 'cobre', '-' ),
( 'redondo',   '15',  1.44960,   6.898,   1.65000,   10.422,  14.79000,    67.6230, '2.5,   4.12600, 3.0,   4.95100, 6.0,   9.9030',    8.293, 'cobre', '-' ),
( 'redondo',   '16',  1.29090,   7.746,   1.30900,   13.141,  11.73000,    85.2710, '2.5,   3.27200, 3.0,   3.92700, 6.0,   7.8530',   10.457, 'cobre', '-' ),
( 'redondo',   '17',  1.14960,   8.699,   1.03800,   16.571,   9.30000,   107.5200, '2.5,   2.59500, 3.0,   3.11400, 6.0,   6.2280',   13.187, 'cobre', '-' ),
( 'redondo',   '18',  1.02380,   9.768,   0.82300,   20.895,   7.37600,   135.5800, '2.5,   2.05800, 3.0,   2.46900, 6.0,   4.9390',   16.628, 'cobre', '-' ),
( 'redondo',   '19',  0.91170,  10.969,   0.65300,   26.348,   5.84900,   170.9700, '2.5,   1.63200, 3.0,   1.95800, 6.0,   3.9170',   20.967, 'cobre', '-' ),
( 'redondo',   '20',  0.81190,  12.317,   0.51800,   33.224,   4.63900,   215.5800, '2.5,   1.29400, 3.0,   1.55300, 6.0,   3.1060',   26.439, 'cobre', '-' ),
( 'redondo',   '21',  0.72300,  13.831,   0.41100,   41.894,   3.67900,   271.8400, '2.5,   1.02600, 3.0,   1.23200, 6.0,   2.4630',   33.339, 'cobre', '-' ),
( 'redondo',   '22',  0.64390,  15.531,   0.32600,   52.828,   2.91700,   342.7900, '2.5,   0.81400, 3.0,   0.97700, 6.0,   1.9540',   42.039, 'cobre', '-' ),
( 'redondo',   '23',  0.57340,  17.441,   0.25800,   66.614,   2.31400,   432.2400, '2.5,   0.64600, 3.0,   0.77500, 6.0,   1.5490',   53.010, 'cobre', '-' ),
( 'redondo',   '24',  0.51060,  19.585,   0.20500,   83.998,   1.83500,   545.0500, '2.5,   0.51200, 3.0,   0.61400, 6.0,   1.2290',   66.844, 'cobre', '-' ),
( 'redondo',   '25',  0.45470,  21.992,   0.16200,  105.919,   1.45500,   687.2900, '2.5,   0.40600, 3.0,   0.48700, 6.0,   0.9740',   84.288, 'cobre', '-' ),
( 'redondo',   '26',  0.40490,  24.696,   0.12900,  133.560,   1.15400,   866.6500, '2.5,   0.32200, 3.0,   0.38600, 6.0,   0.7730',  106.284, 'cobre', '-' ),
( 'redondo',   '27',  0.36060,  27.731,   0.10200,  168.415,   0.91510,  1092.8000, '2.5,   0.25500, 3.0,   0.30600, 6.0,   0.6130',  134.021, 'cobre', '-' ),
( 'redondo',   '28',  0.32110,  31.140,   0.08100,  212.367,   0.72570,  1378.0000, '2.5,   0.20200, 3.0,   0.24300, 6.0,   0.4860',  168.996, 'cobre', '-' ),
( 'redondo',   '29',  0.28600,  34.968,   0.06420,  267.788,   0.57550,  1737.6000, '2.5,   0.16100, 3.0,   0.19300, 6.0,   0.3850',  213.099, 'cobre', '-' ),
( 'redondo',   '30',  0.25470,  39.267,   0.05090,  337.672,   0.45640,  2191.1000, '2.5,   0.12700, 3.0,   0.15300, 6.0,   0.3060',  268.711, 'cobre', '-' ),
( 'redondo',   '31',  0.22680,  44.094,   0.04040,  425.793,   0.36190,  2762.9000, '2.5,   0.10100, 3.0,   0.12100, 6.0,   0.2420',  338.836, 'cobre', '-' ),
( 'redondo',   '32',  0.20200,  49.514,   0.03200,  536.912,   0.28700,  3483.9000, '2.5,   0.08010, 3.0,   0.09610, 6.0,   0.1920',  427.261, 'cobre', '-' ),
( 'redondo',   '33',  0.17990,  55.601,   0.02540,  677.029,   0.22760,  4393.1000, '2.5,   0.06350, 3.0,   0.07620, 6.0,   0.1520',  538.763, 'cobre', '-' ),
( 'redondo',   '34',  0.16020,  62.436,   0.02010,  853.712,   0.18050,  5539.6000, '2.5,   0.05040, 3.0,   0.06040, 6.0,   0.1210',  679.363, 'cobre', '-' ),
( 'redondo',   '35',  0.14260,  70.111,   0.01600, 1076.504,   0.14320,  6985.2000, '2.5,   0.03990, 3.0,   0.04790, 6.0,   0.0959',  856.655, 'cobre', '-' ),
( 'redondo',   '36',  0.12700,  78.730,   0.01270, 1357.437,   0.11350,  8808.1000, '2.5,   0.03170, 3.0,   0.03800, 6.0,   0.0760', 1080.215, 'cobre', '-' ),
( 'redondo',   '37',  0.11310,  88.408,   0.01000, 1711.686,   0.09004, 11106.8000, '2.5,   0.02510, 3.0,   0.03010, 6.0,   0.0603', 1362.116, 'cobre', '-' ),
( 'redondo',   '38',  0.10070,  99.276,   0.00797, 2158.381,   0.07140, 14005.3000, '2.5,   0.01990, 3.0,   0.02390, 6.0,   0.0478', 1717.586, 'cobre', '-' ),
( 'redondo',   '39',  0.08970, 111.480,   0.00632, 2721.651,   0.05662, 17660.2000, '2.5,   0.01580, 3.0,   0.01900, 6.0,   0.0379', 2165.821, 'cobre', '-' ),
( 'redondo',   '40',  0.07988, 125.184,   0.00501, 3431.916,   0.04491, 22269.0000, '2.5,   0.01250, 3.0,   0.01500, 6.0,   0.0301', 2731.032, 'cobre', '-' ),
( 'redondo',   '41',  0.07114, 140.573,   0.00397, 4327.537,   0.03561, 28080.5000, '2.5,   0.00994, 3.0,   0.01190, 6.0,   0.0238', 3443.745, 'cobre', '-' ),
( 'redondo',   '42',  0.06335, 157.853,   0.00315, 5456.888,   0.02824, 35408.6000, '2.5,   0.00788, 3.0,   0.00946, 6.0,   0.0189', 4342.454, 'cobre', '-' ),
( 'redondo',   '43',  0.05642, 177.258,   0.00250, 6880.963,   0.02240, 44649.1000, '2.5,   0.00625, 3.0,   0.00750, 6.0,   0.0150', 5475.697, 'cobre', '-' ),
( 'redondo',   '44',  0.05024, 199.048,   0.00198, 8676.677,   0.01776, 56301.1000, '2.5,   0.00496, 3.0,   0.00595, 6.0,   0.0119', 6904.681, 'cobre', '-' );