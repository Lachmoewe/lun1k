#include <stdlib.h>
#include "main.h"
#include <stdio.h>
#include <math.h>
#include "../libs/text.h"



// table size: 8kb
static uint16_t sin_table[0x1000] =
{
	0,12,25,37,50,62,75,87,100,113,125,138,150,163,175,188,201,213,226,238,251,263,276,288,301,314,326,339,351,364,376,389,402,414,427,439,452,464,477,489,502,515,527,540,552,565,577,590,603,615,628,640,653,665,678,690,703,716,728,741,753,766,778,791,804,816,829,841,854,866,879,891,904,917,929,942,954,967,979,992,1004,1017,1030,1042,1055,1067,1080,1092,1105,1117,1130,1143,1155,1168,1180,1193,1205,1218,1230,1243,1256,1268,1281,1293,1306,1318,1331,1343,1356,1369,1381,1394,1406,1419,1431,1444,1456,1469,1482,1494,1507,1519,1532,1544,1557,1569,1582,1595,1607,1620,1632,1645,1657,1670,1682,1695,1707,1720,1733,1745,1758,1770,1783,1795,1808,1820,1833,1845,1858,1871,1883,1896,1908,1921,1933,1946,1958,1971,1983,1996,2008,2021,2034,2046,2059,2071,2084,2096,2109,2121,2134,2146,2159,2171,2184,2197,2209,2222,2234,2247,2259,2272,2284,2297,2309,2322,2334,2347,2359,2372,2385,2397,2410,2422,2435,2447,2460,2472,2485,2497,2510,2522,2535,2547,2560,2572,2585,2598,2610,2623,2635,2648,2660,2673,2685,2698,2710,2723,2735,2748,2760,2773,2785,2798,2810,2823,2835,2848,2860,2873,2885,2898,2911,2923,2936,2948,2961,2973,2986,2998,3011,3023,3036,3048,3061,3073,3086,3098,3111,3123,3136,3148,3161,3173,3186,3198,3211,3223,3236,3248,3261,3273,3286,3298,3311,3323,3336,3348,3361,3373,3386,3398,3411,3423,3436,3448,3461,3473,3486,3498,3511,3523,3536,3548,3561,3573,3586,3598,3611,3623,3636,3648,3661,3673,3686,3698,3710,3723,3735,3748,3760,3773,3785,3798,3810,3823,3835,3848,3860,3873,3885,3898,3910,3923,3935,3948,3960,3972,3985,3997,4010,4022,4035,4047,4060,4072,4085,4097,4110,4122,4135,4147,4160,4172,4184,4197,4209,4222,4234,4247,4259,4272,4284,4297,4309,4321,4334,4346,4359,4371,4384,4396,4409,4421,4434,4446,4458,4471,4483,4496,4508,4521,4533,4546,4558,4570,4583,4595,4608,4620,4633,4645,4657,4670,4682,4695,4707,4720,4732,4745,4757,4769,4782,4794,4807,4819,4832,4844,4856,4869,4881,4894,4906,4918,4931,4943,4956,4968,4981,4993,5005,5018,5030,5043,5055,5068,5080,5092,5105,5117,5130,5142,5154,5167,5179,5192,5204,5216,5229,5241,5254,5266,5278,5291,5303,5316,5328,5340,5353,5365,5378,5390,5402,5415,5427,5440,5452,5464,5477,5489,5501,5514,5526,5539,5551,5563,5576,5588,5601,5613,5625,5638,5650,5662,5675,5687,5700,5712,5724,5737,5749,5761,5774,5786,5799,5811,5823,5836,5848,5860,5873,5885,5897,5910,5922,5934,5947,5959,5972,5984,5996,6009,6021,6033,6046,6058,6070,6083,6095,6107,6120,6132,6144,6157,6169,6181,6194,6206,6218,6231,6243,6255,6268,6280,6292,6305,6317,6329,6342,6354,6366,6379,6391,6403,6416,6428,6440,6453,6465,6477,6490,6502,6514,6527,6539,6551,6563,6576,6588,6600,6613,6625,6637,6650,6662,6674,6687,6699,6711,6723,6736,6748,6760,6773,6785,6797,6809,6822,6834,6846,6859,6871,6883,6895,6908,6920,6932,6945,6957,6969,6981,6994,7006,7018,7031,7043,7055,7067,7080,7092,7104,7116,7129,7141,7153,7165,7178,7190,7202,7214,7227,7239,7251,7263,7276,7288,7300,7312,7325,7337,7349,7361,7374,7386,7398,7410,7423,7435,7447,7459,7472,7484,7496,7508,7521,7533,7545,7557,7569,7582,7594,7606,7618,7631,7643,7655,7667,7679,7692,7704,7716,7728,7740,7753,7765,7777,7789,7801,7814,7826,7838,7850,7862,7875,7887,7899,7911,7923,7936,7948,7960,7972,7984,7997,8009,8021,8033,8045,8057,8070,8082,8094,8106,8118,8131,8143,8155,8167,8179,8191,8204,8216,8228,8240,8252,8264,8276,8289,8301,8313,8325,8337,8349,8362,8374,8386,8398,8410,8422,8434,8447,8459,8471,8483,8495,8507,8519,8532,8544,8556,8568,8580,8592,8604,8616,8629,8641,8653,8665,8677,8689,8701,8713,8725,8738,8750,8762,8774,8786,8798,8810,8822,8834,8846,8859,8871,8883,8895,8907,8919,8931,8943,8955,8967,8979,8992,9004,9016,9028,9040,9052,9064,9076,9088,9100,9112,9124,9136,9149,9161,9173,9185,9197,9209,9221,9233,9245,9257,9269,9281,9293,9305,9317,9329,9341,9353,9365,9377,9390,9402,9414,9426,9438,9450,9462,9474,9486,9498,9510,9522,9534,9546,9558,9570,9582,9594,9606,9618,9630,9642,9654,9666,9678,9690,9702,9714,9726,9738,9750,9762,9774,9786,9798,9810,9822,9834,9846,9858,9870,9882,9894,9906,9918,9930,9942,9954,9966,9978,9990,10002,10014,10026,10037,10049,10061,10073,10085,10097,10109,10121,10133,10145,10157,10169,10181,10193,10205,10217,10229,10241,10253,10264,10276,10288,10300,10312,10324,10336,10348,10360,10372,10384,10396,10408,10419,10431,10443,10455,10467,10479,10491,10503,10515,10527,10538,10550,10562,10574,10586,10598,10610,10622,10634,10645,10657,10669,10681,10693,10705,10717,10729,10740,10752,10764,10776,10788,10800,10812,10824,10835,10847,10859,10871,10883,10895,10906,10918,10930,10942,10954,10966,10978,10989,11001,11013,11025,11037,11049,11060,11072,11084,11096,11108,11119,11131,11143,11155,11167,11179,11190,11202,11214,11226,11238,11249,11261,11273,11285,11297,11308,11320,11332,11344,11356,11367,11379,11391,11403,11414,11426,11438,11450,11462,11473,11485,11497,11509,11520,11532,11544,11556,11567,11579,11591,11603,11614,11626,11638,11650,11661,11673,11685,11697,11708,11720,11732,11744,11755,11767,11779,11790,11802,11814,11826,11837,11849,11861,11872,11884,11896,11908,11919,11931,11943,11954,11966,11978,11989,12001,12013,12025,12036,12048,12060,12071,12083,12095,12106,12118,12130,12141,12153,12165,12176,12188,12200,12211,12223,12235,12246,12258,12270,12281,12293,12305,12316,12328,12339,12351,12363,12374,12386,12398,12409,12421,12432,12444,12456,12467,12479,12491,12502,12514,12525,12537,12549,12560,12572,12583,12595,12607,12618,12630,12641,12653,12665,12676,12688,12699,12711,12723,12734,12746,12757,12769,12780,12792,12804,12815,12827,12838,12850,12861,12873,12884,12896,12908,12919,12931,12942,12954,12965,12977,12988,13000,13011,13023,13034,13046,13058,13069,13081,13092,13104,13115,13127,13138,13150,13161,13173,13184,13196,13207,13219,13230,13242,13253,13265,13276,13288,13299,13311,13322,13334,13345,13356,13368,13379,13391,13402,13414,13425,13437,13448,13460,13471,13483,13494,13505,13517,13528,13540,13551,13563,13574,13586,13597,13608,13620,13631,13643,13654,13666,13677,13688,13700,13711,13723,13734,13745,13757,13768,13780,13791,13802,13814,13825,13837,13848,13859,13871,13882,13893,13905,13916,13928,13939,13950,13962,13973,13984,13996,14007,14019,14030,14041,14053,14064,14075,14087,14098,14109,14121,14132,14143,14155,14166,14177,14189,14200,14211,14223,14234,14245,14257,14268,14279,14290,14302,14313,14324,14336,14347,14358,14370,14381,14392,14403,14415,14426,14437,14449,14460,14471,14482,14494,14505,14516,14527,14539,14550,14561,14572,14584,14595,14606,14617,14629,14640,14651,14662,14674,14685,14696,14707,14719,14730,14741,14752,14763,14775,14786,14797,14808,14820,14831,14842,14853,14864,14876,14887,14898,14909,14920,14931,14943,14954,14965,14976,14987,14999,15010,15021,15032,15043,15054,15065,15077,15088,15099,15110,15121,15132,15144,15155,15166,15177,15188,15199,15210,15221,15233,15244,15255,15266,15277,15288,15299,15310,15322,15333,15344,15355,15366,15377,15388,15399,15410,15421,15432,15444,15455,15466,15477,15488,15499,15510,15521,15532,15543,15554,15565,15576,15587,15598,15610,15621,15632,15643,15654,15665,15676,15687,15698,15709,15720,15731,15742,15753,15764,15775,15786,15797,15808,15819,15830,15841,15852,15863,15874,15885,15896,15907,15918,15929,15940,15951,15962,15973,15984,15995,16006,16017,16028,16039,16050,16060,16071,16082,16093,16104,16115,16126,16137,16148,16159,16170,16181,16192,16203,16214,16224,16235,16246,16257,16268,16279,16290,16301,16312,16323,16334,16344,16355,16366,16377,16388,16399,16410,16421,16431,16442,16453,16464,16475,16486,16497,16507,16518,16529,16540,16551,16562,16573,16583,16594,16605,16616,16627,16638,16648,16659,16670,16681,16692,16702,16713,16724,16735,16746,16756,16767,16778,16789,16800,16810,16821,16832,16843,16854,16864,16875,16886,16897,16907,16918,16929,16940,16950,16961,16972,16983,16993,17004,17015,17026,17036,17047,17058,17069,17079,17090,17101,17111,17122,17133,17144,17154,17165,17176,17186,17197,17208,17218,17229,17240,17250,17261,17272,17283,17293,17304,17315,17325,17336,17347,17357,17368,17378,17389,17400,17410,17421,17432,17442,17453,17464,17474,17485,17495,17506,17517,17527,17538,17549,17559,17570,17580,17591,17602,17612,17623,17633,17644,17655,17665,17676,17686,17697,17707,17718,17729,17739,17750,17760,17771,17781,17792,17802,17813,17824,17834,17845,17855,17866,17876,17887,17897,17908,17918,17929,17939,17950,17960,17971,17981,17992,18002,18013,18023,18034,18044,18055,18065,18076,18086,18097,18107,18118,18128,18139,18149,18160,18170,18180,18191,18201,18212,18222,18233,18243,18254,18264,18274,18285,18295,18306,18316,18327,18337,18347,18358,18368,18379,18389,18399,18410,18420,18431,18441,18451,18462,18472,18482,18493,18503,18514,18524,18534,18545,18555,18565,18576,18586,18596,18607,18617,18627,18638,18648,18658,18669,18679,18689,18700,18710,18720,18731,18741,18751,18762,18772,18782,18792,18803,18813,18823,18834,18844,18854,18864,18875,18885,18895,18906,18916,18926,18936,18947,18957,18967,18977,18988,18998,19008,19018,19028,19039,19049,19059,19069,19080,19090,19100,19110,19120,19131,19141,19151,19161,19171,19182,19192,19202,19212,19222,19232,19243,19253,19263,19273,19283,19293,19304,19314,19324,19334,19344,19354,19364,19375,19385,19395,19405,19415,19425,19435,19445,19456,19466,19476,19486,19496,19506,19516,19526,19536,19546,19557,19567,19577,19587,19597,19607,19617,19627,19637,19647,19657,19667,19677,19687,19697,19707,19717,19727,19738,19748,19758,19768,19778,19788,19798,19808,19818,19828,19838,19848,19858,19868,19878,19888,19898,19908,19918,19928,19937,19947,19957,19967,19977,19987,19997,20007,20017,20027,20037,20047,20057,20067,20077,20087,20097,20107,20116,20126,20136,20146,20156,20166,20176,20186,20196,20206,20216,20225,20235,20245,20255,20265,20275,20285,20295,20304,20314,20324,20334,20344,20354,20363,20373,20383,20393,20403,20413,20422,20432,20442,20452,20462,20472,20481,20491,20501,20511,20521,20530,20540,20550,20560,20570,20579,20589,20599,20609,20618,20628,20638,20648,20657,20667,20677,20687,20696,20706,20716,20726,20735,20745,20755,20765,20774,20784,20794,20803,20813,20823,20832,20842,20852,20862,20871,20881,20891,20900,20910,20920,20929,20939,20949,20958,20968,20978,20987,20997,21007,21016,21026,21035,21045,21055,21064,21074,21084,21093,21103,21112,21122,21132,21141,21151,21160,21170,21180,21189,21199,21208,21218,21227,21237,21247,21256,21266,21275,21285,21294,21304,21314,21323,21333,21342,21352,21361,21371,21380,21390,21399,21409,21418,21428,21437,21447,21456,21466,21475,21485,21494,21504,21513,21523,21532,21542,21551,21561,21570,21579,21589,21598,21608,21617,21627,21636,21646,21655,21664,21674,21683,21693,21702,21712,21721,21730,21740,21749,21759,21768,21777,21787,21796,21805,21815,21824,21834,21843,21852,21862,21871,21880,21890,21899,21908,21918,21927,21936,21946,21955,21964,21974,21983,21992,22002,22011,22020,22030,22039,22048,22057,22067,22076,22085,22095,22104,22113,22122,22132,22141,22150,22159,22169,22178,22187,22196,22206,22215,22224,22233,22243,22252,22261,22270,22280,22289,22298,22307,22316,22326,22335,22344,22353,22362,22372,22381,22390,22399,22408,22417,22427,22436,22445,22454,22463,22472,22481,22491,22500,22509,22518,22527,22536,22545,22554,22564,22573,22582,22591,22600,22609,22618,22627,22636,22645,22654,22664,22673,22682,22691,22700,22709,22718,22727,22736,22745,22754,22763,22772,22781,22790,22799,22808,22817,22826,22835,22844,22853,22862,22871,22880,22889,22898,22907,22916,22925,22934,22943,22952,22961,22970,22979,22988,22997,23006,23015,23024,23033,23042,23051,23060,23068,23077,23086,23095,23104,23113,23122,23131,23140,23149,23158,23166,23175,23184,23193,23202,23211,23220,23229,23237,23246,23255,23264,23273,23282,23290,23299,23308,23317,23326,23335,23343,23352,23361,23370,23379,23388,23396,23405,23414,23423,23431,23440,23449,23458,23467,23475,23484,23493,23502,23510,23519,23528,23537,23545,23554,23563,23572,23580,23589,23598,23606,23615,23624,23633,23641,23650,23659,23667,23676,23685,23693,23702,23711,23719,23728,23737,23745,23754,23763,23771,23780,23789,23797,23806,23815,23823,23832,23840,23849,23858,23866,23875,23883,23892,23901,23909,23918,23926,23935,23944,23952,23961,23969,23978,23986,23995,24004,24012,24021,24029,24038,24046,24055,24063,24072,24080,24089,24097,24106,24114,24123,24131,24140,24148,24157,24165,24174,24182,24191,24199,24208,24216,24225,24233,24242,24250,24259,24267,24275,24284,24292,24301,24309,24318,24326,24334,24343,24351,24360,24368,24376,24385,24393,24402,24410,24418,24427,24435,24443,24452,24460,24469,24477,24485,24494,24502,24510,24519,24527,24535,24544,24552,24560,24569,24577,24585,24593,24602,24610,24618,24627,24635,24643,24651,24660,24668,24676,24685,24693,24701,24709,24718,24726,24734,24742,24751,24759,24767,24775,24783,24792,24800,24808,24816,24825,24833,24841,24849,24857,24865,24874,24882,24890,24898,24906,24914,24923,24931,24939,24947,24955,24963,24972,24980,24988,24996,25004,25012,25020,25028,25036,25045,25053,25061,25069,25077,25085,25093,25101,25109,25117,25125,25133,25142,25150,25158,25166,25174,25182,25190,25198,25206,25214,25222,25230,25238,25246,25254,25262,25270,25278,25286,25294,25302,25310,25318,25326,25334,25342,25350,25358,25366,25374,25382,25390,25397,25405,25413,25421,25429,25437,25445,25453,25461,25469,25477,25485,25492,25500,25508,25516,25524,25532,25540,25548,25555,25563,25571,25579,25587,25595,25603,25610,25618,25626,25634,25642,25650,25657,25665,25673,25681,25689,25696,25704,25712,25720,25728,25735,25743,25751,25759,25766,25774,25782,25790,25797,25805,25813,25821,25828,25836,25844,25852,25859,25867,25875,25882,25890,25898,25906,25913,25921,25929,25936,25944,25952,25959,25967,25975,25982,25990,25998,26005,26013,26020,26028,26036,26043,26051,26059,26066,26074,26081,26089,26097,26104,26112,26119,26127,26135,26142,26150,26157,26165,26172,26180,26188,26195,26203,26210,26218,26225,26233,26240,26248,26255,26263,26270,26278,26285,26293,26300,26308,26315,26323,26330,26338,26345,26353,26360,26368,26375,26383,26390,26397,26405,26412,26420,26427,26435,26442,26449,26457,26464,26472,26479,26487,26494,26501,26509,26516,26523,26531,26538,26546,26553,26560,26568,26575,26582,26590,26597,26604,26612,26619,26626,26634,26641,26648,26656,26663,26670,26678,26685,26692,26699,26707,26714,26721,26728,26736,26743,26750,26758,26765,26772,26779,26786,26794,26801,26808,26815,26823,26830,26837,26844,26851,26859,26866,26873,26880,26887,26895,26902,26909,26916,26923,26930,26938,26945,26952,26959,26966,26973,26980,26988,26995,27002,27009,27016,27023,27030,27037,27044,27052,27059,27066,27073,27080,27087,27094,27101,27108,27115,27122,27129,27136,27143,27150,27157,27164,27171,27178,27186,27193,27200,27207,27214,27221,27228,27235,27241,27248,27255,27262,27269,27276,27283,27290,27297,27304,27311,27318,27325,27332,27339,27346,27353,27360,27367,27373,27380,27387,27394,27401,27408,27415,27422,27429,27435,27442,27449,27456,27463,27470,27477,27483,27490,27497,27504,27511,27518,27524,27531,27538,27545,27552,27558,27565,27572,27579,27586,27592,27599,27606,27613,27619,27626,27633,27640,27646,27653,27660,27667,27673,27680,27687,27694,27700,27707,27714,27720,27727,27734,27740,27747,27754,27760,27767,27774,27780,27787,27794,27800,27807,27814,27820,27827,27834,27840,27847,27854,27860,27867,27873,27880,27887,27893,27900,27906,27913,27919,27926,27933,27939,27946,27952,27959,27965,27972,27978,27985,27992,27998,28005,28011,28018,28024,28031,28037,28044,28050,28057,28063,28070,28076,28083,28089,28096,28102,28108,28115,28121,28128,28134,28141,28147,28154,28160,28166,28173,28179,28186,28192,28198,28205,28211,28218,28224,28230,28237,28243,28250,28256,28262,28269,28275,28281,28288,28294,28300,28307,28313,28319,28326,28332,28338,28345,28351,28357,28363,28370,28376,28382,28389,28395,28401,28407,28414,28420,28426,28432,28439,28445,28451,28457,28464,28470,28476,28482,28488,28495,28501,28507,28513,28519,28526,28532,28538,28544,28550,28556,28563,28569,28575,28581,28587,28593,28599,28606,28612,28618,28624,28630,28636,28642,28648,28654,28661,28667,28673,28679,28685,28691,28697,28703,28709,28715,28721,28727,28733,28739,28745,28751,28757,28763,28769,28775,28781,28787,28793,28799,28805,28811,28817,28823,28829,28835,28841,28847,28853,28859,28865,28871,28877,28883,28889,28895,28901,28907,28913,28918,28924,28930,28936,28942,28948,28954,28960,28966,28971,28977,28983,28989,28995,29001,29007,29012,29018,29024,29030,29036,29042,29047,29053,29059,29065,29071,29076,29082,29088,29094,29100,29105,29111,29117,29123,29128,29134,29140,29146,29151,29157,29163,29169,29174,29180,29186,29191,29197,29203,29209,29214,29220,29226,29231,29237,29243,29248,29254,29260,29265,29271,29277,29282,29288,29293,29299,29305,29310,29316,29322,29327,29333,29338,29344,29350,29355,29361,29366,29372,29377,29383,29389,29394,29400,29405,29411,29416,29422,29427,29433,29438,29444,29449,29455,29460,29466,29471,29477,29482,29488,29493,29499,29504,29510,29515,29521,29526,29532,29537,29542,29548,29553,29559,29564,29570,29575,29580,29586,29591,29597,29602,29607,29613,29618,29623,29629,29634,29640,29645,29650,29656,29661,29666,29672,29677,29682,29688,29693,29698,29703,29709,29714,29719,29725,29730,29735,29741,29746,29751,29756,29762,29767,29772,29777,29783,29788,29793,29798,29803,29809,29814,29819,29824,29830,29835,29840,29845,29850,29855,29861,29866,29871,29876,29881,29886,29892,29897,29902,29907,29912,29917,29922,29928,29933,29938,29943,29948,29953,29958,29963,29968,29973,29978,29984,29989,29994,29999,30004,30009,30014,30019,30024,30029,30034,30039,30044,30049,30054,30059,30064,30069,30074,30079,30084,30089,30094,30099,30104,30109,30114,30119,30124,30129,30134,30138,30143,30148,30153,30158,30163,30168,30173,30178,30183,30188,30192,30197,30202,30207,30212,30217,30222,30226,30231,30236,30241,30246,30251,30256,30260,30265,30270,30275,30280,30284,30289,30294,30299,30304,30308,30313,30318,30323,30327,30332,30337,30342,30346,30351,30356,30361,30365,30370,30375,30379,30384,30389,30394,30398,30403,30408,30412,30417,30422,30426,30431,30436,30440,30445,30450,30454,30459,30463,30468,30473,30477,30482,30487,30491,30496,30500,30505,30509,30514,30519,30523,30528,30532,30537,30541,30546,30551,30555,30560,30564,30569,30573,30578,30582,30587,30591,30596,30600,30605,30609,30614,30618,30623,30627,30632,30636,30640,30645,30649,30654,30658,30663,30667,30672,30676,30680,30685,30689,30694,30698,30702,30707,30711,30716,30720,30724,30729,30733,30737,30742,30746,30750,30755,30759,30763,30768,30772,30776,30781,30785,30789,30794,30798,30802,30806,30811,30815,30819,30823,30828,30832,30836,30840,30845,30849,30853,30857,30862,30866,30870,30874,30879,30883,30887,30891,30895,30899,30904,30908,30912,30916,30920,30924,30929,30933,30937,30941,30945,30949,30953,30958,30962,30966,30970,30974,30978,30982,30986,30990,30994,30998,31003,31007,31011,31015,31019,31023,31027,31031,31035,31039,31043,31047,31051,31055,31059,31063,31067,31071,31075,31079,31083,31087,31091,31095,31099,31103,31107,31111,31115,31119,31122,31126,31130,31134,31138,31142,31146,31150,31154,31158,31162,31165,31169,31173,31177,31181,31185,31189,31192,31196,31200,31204,31208,31212,31215,31219,31223,31227,31231,31235,31238,31242,31246,31250,31253,31257,31261,31265,31269,31272,31276,31280,31284,31287,31291,31295,31298,31302,31306,31310,31313,31317,31321,31324,31328,31332,31335,31339,31343,31346,31350,31354,31357,31361,31365,31368,31372,31375,31379,31383,31386,31390,31394,31397,31401,31404,31408,31411,31415,31419,31422,31426,31429,31433,31436,31440,31443,31447,31451,31454,31458,31461,31465,31468,31472,31475,31479,31482,31486,31489,31492,31496,31499,31503,31506,31510,31513,31517,31520,31524,31527,31530,31534,31537,31541,31544,31547,31551,31554,31558,31561,31564,31568,31571,31574,31578,31581,31584,31588,31591,31594,31598,31601,31604,31608,31611,31614,31618,31621,31624,31628,31631,31634,31637,31641,31644,31647,31650,31654,31657,31660,31663,31667,31670,31673,31676,31680,31683,31686,31689,31692,31695,31699,31702,31705,31708,31711,31715,31718,31721,31724,31727,31730,31733,31737,31740,31743,31746,31749,31752,31755,31758,31761,31764,31768,31771,31774,31777,31780,31783,31786,31789,31792,31795,31798,31801,31804,31807,31810,31813,31816,31819,31822,31825,31828,31831,31834,31837,31840,31843,31846,31849,31852,31855,31858,31861,31864,31867,31870,31872,31875,31878,31881,31884,31887,31890,31893,31896,31898,31901,31904,31907,31910,31913,31916,31918,31921,31924,31927,31930,31933,31935,31938,31941,31944,31947,31949,31952,31955,31958,31961,31963,31966,31969,31972,31974,31977,31980,31983,31985,31988,31991,31993,31996,31999,32002,32004,32007,32010,32012,32015,32018,32020,32023,32026,32028,32031,32034,32036,32039,32042,32044,32047,32049,32052,32055,32057,32060,32062,32065,32068,32070,32073,32075,32078,32080,32083,32086,32088,32091,32093,32096,32098,32101,32103,32106,32108,32111,32113,32116,32118,32121,32123,32126,32128,32131,32133,32136,32138,32140,32143,32145,32148,32150,32153,32155,32157,32160,32162,32165,32167,32169,32172,32174,32177,32179,32181,32184,32186,32188,32191,32193,32195,32198,32200,32202,32205,32207,32209,32212,32214,32216,32219,32221,32223,32225,32228,32230,32232,32234,32237,32239,32241,32243,32246,32248,32250,32252,32255,32257,32259,32261,32263,32266,32268,32270,32272,32274,32276,32279,32281,32283,32285,32287,32289,32291,32294,32296,32298,32300,32302,32304,32306,32308,32310,32313,32315,32317,32319,32321,32323,32325,32327,32329,32331,32333,32335,32337,32339,32341,32343,32345,32347,32349,32351,32353,32355,32357,32359,32361,32363,32365,32367,32369,32371,32373,32375,32377,32379,32381,32383,32384,32386,32388,32390,32392,32394,32396,32398,32400,32401,32403,32405,32407,32409,32411,32413,32414,32416,32418,32420,32422,32424,32425,32427,32429,32431,32433,32434,32436,32438,32440,32441,32443,32445,32447,32449,32450,32452,32454,32455,32457,32459,32461,32462,32464,32466,32467,32469,32471,32472,32474,32476,32477,32479,32481,32482,32484,32486,32487,32489,32491,32492,32494,32496,32497,32499,32500,32502,32504,32505,32507,32508,32510,32511,32513,32515,32516,32518,32519,32521,32522,32524,32525,32527,32528,32530,32531,32533,32534,32536,32537,32539,32540,32542,32543,32545,32546,32548,32549,32550,32552,32553,32555,32556,32558,32559,32560,32562,32563,32565,32566,32567,32569,32570,32572,32573,32574,32576,32577,32578,32580,32581,32582,32584,32585,32586,32588,32589,32590,32592,32593,32594,32595,32597,32598,32599,32600,32602,32603,32604,32606,32607,32608,32609,32610,32612,32613,32614,32615,32617,32618,32619,32620,32621,32622,32624,32625,32626,32627,32628,32629,32631,32632,32633,32634,32635,32636,32637,32638,32640,32641,32642,32643,32644,32645,32646,32647,32648,32649,32650,32651,32652,32654,32655,32656,32657,32658,32659,32660,32661,32662,32663,32664,32665,32666,32667,32668,32669,32670,32671,32672,32672,32673,32674,32675,32676,32677,32678,32679,32680,32681,32682,32683,32684,32684,32685,32686,32687,32688,32689,32690,32691,32691,32692,32693,32694,32695,32696,32696,32697,32698,32699,32700,32700,32701,32702,32703,32704,32704,32705,32706,32707,32707,32708,32709,32710,32710,32711,32712,32713,32713,32714,32715,32715,32716,32717,32718,32718,32719,32720,32720,32721,32722,32722,32723,32723,32724,32725,32725,32726,32727,32727,32728,32728,32729,32730,32730,32731,32731,32732,32733,32733,32734,32734,32735,32735,32736,32736,32737,32738,32738,32739,32739,32740,32740,32741,32741,32742,32742,32743,32743,32744,32744,32744,32745,32745,32746,32746,32747,32747,32748,32748,32748,32749,32749,32750,32750,32750,32751,32751,32752,32752,32752,32753,32753,32753,32754,32754,32754,32755,32755,32755,32756,32756,32756,32757,32757,32757,32758,32758,32758,32758,32759,32759,32759,32760,32760,32760,32760,32761,32761,32761,32761,32761,32762,32762,32762,32762,32763,32763,32763,32763,32763,32763,32764,32764,32764,32764,32764,32764,32765,32765,32765,32765,32765,32765,32765,32765,32765,32766,32766,32766,32766,32766,32766,32766,
	32766,32766,32766,32766,32766,32766,32766,32766,32766,32766,32766,32766,
};

// input 0..16383 (0..0x3fff) (14bit); output 0..65535 (0..0xffff) (16bit)
static uint16_t sini(uint16_t x)
{
	x = x & 0x3fff;

	if(x < 0x1000) return sin_table[x]+0x8000;
	if(x < 0x2000) return sin_table[0x1fff-x]+0x8000;
	if(x < 0x3000) return 0x7fff-sin_table[x-0x2000];
	return 0x7fff-sin_table[0x3fff-x]; 

}

static double pythagoras( double side1, double side2 )
{
	return sqrt(pow( side1, 2 ) + pow( side2, 2 ));
}


static uint8_t tick(char* nick) {

	static uint16_t a = 0;
	
	uint8_t x, y;

	uint16_t sin1 = sini(a);
	double x0 = (double)sini(a*4)/256-64;
	double y0 = (double)sini((a*4)+0x1000)/256-64;
	double x1 = (double)sini(a*5)/128-128;
	double y1 = (double)sini((a*5)+0x1000)/128-128;
		
	for(y = 0; y < LED_HEIGHT; y++) 
	{
		uint16_t y_part =  sini(sin1+y*20);


		for(x = 0; x < LED_WIDTH; x++) 
		{
			
			double dist = pythagoras(x0-x,y0-y);
			double dist2 = pythagoras(y1-x,x1-y);


			uint16_t h = sini(sin1+x*20)+ y_part + sini(dist*500) + sini(dist2*300);
			uint16_t h2 = sini(sin1+x*30)+ y_part + sini(dist*200) + sini(dist2*350);
			setLedXY(
				x,y,
				sini((h>>2)+a*500)>>8,
				sini((h2>>2)+a*320+0x1555)>>8,
				sini((h>>2)+a*630+0x2aaa)>>8
			);
		}
	}
	uint16_t text_width = get_text_width_16pt(nick);
	draw_text_inv_16pt((LED_WIDTH/2)-(text_width/2),LED_HEIGHT/2-11, nick);
	a+=1;
	if(a==0x4000)
	{
		a=0;
	}
	return 0;
}
/*static void key(uint8_t key) {
}*/

static void init(void) ATTRIBUTES

void init(void) {
//	registerApp(start, key);
	registerAnimation(tick, 4, 450);
}




