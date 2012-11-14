/* Based on: http://lodev.org/cgtutor/tunnel.html */

/*
 *
 * this version uses only about 8k ram (184k less than tunnel.c)
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "main.h"
#include "libs/text.h"
#include "libs/math.h"

#define MIN(a, b) (a < b ? a : b)

uint16_t nr, ng, nb;

uint16_t h;
uint16_t s=255;

uint16_t table[] = { 0,1,2,2,3,4,5,5,6,7,8,9,9,10,11,12,13,13,14,15,16,17,17,18,19,20,21,21,22,23,24,25,25,26,27,28,28,29,30,31,32,32,33,34,35,36,36,37,38,39,40,40,41,42,43,44,44,45,46,47,48,48,49,50,51,51,52,53,54,55,55,56,57,58,59,59,60,61,62,63,63,64,65,66,67,67,68,69,70,70,71,72,73,74,74,75,76,77,78,78,79,80,81,82,82,83,84,85,86,86,87,88,89,89,90,91,92,93,93,94,95,96,97,97,98,99,100,101,101,102,103,104,104,105,106,107,108,108,109,110,111,112,112,113,114,115,116,116,117,118,119,119,120,121,122,123,123,124,125,126,127,127,128,129,130,131,131,132,133,134,134,135,136,137,138,138,139,140,141,142,142,143,144,145,146,146,147,148,149,150,150,151,152,153,153,154,155,156,157,157,158,159,160,161,161,162,163,164,165,165,166,167,168,168,169,170,171,172,172,173,174,175,176,176,177,178,179,180,180,181,182,183,183,184,185,186,187,187,188,189,190,191,191,192,193,194,195,195,196,197,198,199,199,200,201,202,202,203,204,205,206,206,207,208,209,210,210,211,212,213,214,214,215,216,217,218,218,219,220,
	221,221,222,223,224,225,225,226,227,228,229,229,230,231,232,233,233,234,235,236,237,237,238,239,240,240,241,242,243,244,244,245,246,247,248,248,249,250,251,252,252,253,254,255,256,256,257,258,259,260,260,261,262,263,264,264,265,266,267,268,268,269,270,271,272,272,273,274,275,276,276,277,278,279,280,280,281,282,283,284,284,285,286,287,288,288,289,290,291,292,292,293,294,295,296,296,297,298,299,300,300,301,302,303,304,304,305,306,307,308,308,309,310,311,312,312,313,314,315,316,316,317,318,319,320,320,321,322,323,324,324,325,326,327,328,329,329,330,331,332,333,333,334,335,336,337,337,338,339,340,341,341,342,343,344,345,346,346,347,348,349,350,350,351,352,353,354,355,355,356,357,358,359,359,360,361,362,363,363,364,365,366,367,368,368,369,370,371,372,373,373,374,375,376,377,377,378,379,380,381,382,382,383,384,385,386,387,387,388,389,390,391,391,392,393,394,395,396,396,397,398,399,400,401,401,402,403,404,405,406,406,407,408,409,410,411,412,412,413,414,415,416,417,417,418,
	419,420,421,422,422,423,424,425,426,427,428,428,429,430,431,432,433,433,434,435,436,437,438,439,439,440,441,442,443,444,445,445,446,447,448,449,450,451,451,452,453,454,455,456,457,457,458,459,460,461,462,463,463,464,465,466,467,468,469,470,470,471,472,473,474,475,476,477,477,478,479,480,481,482,483,484,484,485,486,487,488,489,490,491,492,492,493,494,495,496,497,498,499,500,501,501,502,503,504,505,506,507,508,509,510,510,511,512,513,514,515,516,517,518,519,520,520,521,522,523,524,525,526,527,528,529,530,531,531,532,533,534,535,536,537,538,539,540,541,542,543,544,545,545,546,547,548,549,550,551,552,553,554,555,556,557,558,559,560,561,562,563,563,564,565,566,567,568,569,570,571,572,573,574,575,576,577,578,579,580,581,582,583,584,585,586,587,588,589,590,591,592,593,594,595,596,597,598,599,600,601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,617,618,619,620,621,622,623,624,626,627,628,629,630,631,632,633,634,635,636,637,638,639,640,641,642,644,645,646,647,
	648,649,650,651,652,653,654,655,657,658,659,660,661,662,663,664,665,666,668,669,670,671,672,673,674,675,677,678,679,680,681,682,683,685,686,687,688,689,690,692,693,694,695,696,697,699,700,701,702,703,704,706,707,708,709,710,712,713,714,715,716,718,719,720,721,723,724,725,726,727,729,730,731,732,734,735,736,737,739,740,741,742,744,745,746,748,749,750,751,753,754,755,757,758,759,761,762,763,764,766,767,768,770,771,772,774,775,776,778,779,781,782,783,785,786,787,789,790,792,793,794,796,797,799,800,801,803,804,806,807,808,810,811,813,814,816,817,819,820,822,823,824,826,827,829,830,832,833,835,836,838,839,841,842,844,846,847,849,850,852,853,855,856,858,860,861,863,864,866,867,869,871,872,874,875,877,879,880,882,884,885,887,889,890,892,894,895,897,899,900,902,904,905,907,909,911,912,914,916,918,919,921,923,925,926,928,930,932,934,935,937,939,941,943,944,946,948,950,952,954,956,957,959,961,963,965,967,969,971,973,975,977,979,981,982,984,986,988,990,992,994,996,998,1000,1002,
	1005,1007,1009,1011,1013,1015,1017,1019,1021,1023};

void hsv_to_rgb(void)	
{
	uint16_t R,G,B;			

	uint32_t i,f;
	uint16_t p, q, t;

	if( s == 0 ) 
	{
		nr=1023;										// Auf 8 Bit RGB skalieren, nacher nur noch kopieren
		ng=1023;
		nb=1023;	
		return;
	}

	i = (((uint32_t)h) * 6) & 0xFF0000;
	f = ((((uint32_t)h) * 6) - i)>>8;
	i >>= 16;
	p = 65535 - s * 256;
	q = 65535 - s * f;
	t = 65535 - s * (256 - f);

	switch( i )
	{
		case 0:
			R = 65535; G = t; B = p; break;
		case 1:
			R = q; G = 65535; B = p; break;
		case 2:
			R = p; G = 65535; B = t; break;
		case 3:
			R = p; G = q; B = 65535; break;			
		case 4:
			R = t; G = p; B = 65535; break;
		default:								
			R = 65535; G = p; B = q; break;				// case 5:					
	}

	nr=table[R>>6];
	ng=table[G>>6];
	nb=table[B>>6];


}

static uint16_t **zTable;

/* No idea why the one in math.h doesn't work */
static double pythagoras1( double side1, double side2 )
{
	return sqrt(side1*side1+side2*side2);
}

static void init(void) {
    int16_t x, y;
		
	zTable = malloc(LED_WIDTH* sizeof(uint16_t *));

	for(y = 0; y < LED_HEIGHT; y++) 
    {
		zTable[y] = malloc((y+1)*sizeof(uint16_t));
        for(x = 0; x < (y+1); x++) 
        {
            int16_t
                x1 = x - LED_WIDTH,
                y1 = y - LED_HEIGHT;
            double distance =
                1 /
                (pythagoras1(x1, y1)
                 + 1);
            uint16_t z = MIN(0xfff, 0xfff * distance);
            zTable[y][x] = z;
        }
    }
}

static float fast_atan2( float y, float x )
{
	const float ONEQTR_PI = M_PI / 4.0;
	const float THRQTR_PI = 3.0 * M_PI / 4.0;
	float r, angle;
	float abs_y = fabs(y) + 1e-10f;      // kludge to prevent 0/0 condition
	if ( x < 0.0f )
	{
		r = (x + abs_y) / (abs_y - x);
		angle = THRQTR_PI;
	}
	else
	{
		r = (x - abs_y) / (x + abs_y);
		angle = ONEQTR_PI;
	}
	angle += (0.1963f * r * r - 0.9817f) * r;
	if ( y < 0.0f )
		return( -angle );     // negate if in quad III or IV
	else
		return( angle );
}
static uint16_t getA(uint16_t x,uint16_t y)
{
            int16_t
                x1 = x - LED_WIDTH,
                y1 = y - LED_HEIGHT;
            float angle = fast_atan2(x1, y1) ;
            return 0x1fff + (angle * 0x1fff) / 3.1514f;

}
static uint16_t getZ(uint16_t x, uint16_t y)
{

    if(x >= LED_WIDTH)
        x = (LED_WIDTH - 1)-(x-(LED_WIDTH));
    if(y >= LED_HEIGHT)
        y = (LED_HEIGHT - 1)-(y-(LED_HEIGHT));
    if(y > x)
    {
        uint8_t t = x;
        x = y;
        y = t;
    }
    return zTable[x][y];
}


static void deinit(void) {

	// free 
	for(int y = 0; y < LED_HEIGHT; y++) 
    {
		free(zTable[y]);
	}
	free(zTable);
}


static uint32_t __attribute__((always_inline)) getTex(uint16_t a, uint16_t z,uint16_t t) {

	uint32_t r = sini((z<<8)+(a<<2))>>8<<16;
	uint32_t g = sini((sini(t*10)>>9)*z*3)>>8<<8;
	uint32_t b = sini(z*1600+(a>>4))>>8;
	uint32_t b2 = sini((z<<7)+(a<<1))>>8;
			
//			h=t*sini(a*3+z*70)/512;
//			hsv_to_rgb();
//			printf(" %i %i %i %i\n",i,nr,ng,nb);


//	r |= nr>>2<<16;
//	g |= ng>>2<<8;
//	b |= nb>>2;

	return r|g|b|b2;

	//return texGetRGB(z, a >> 6);
}


// as this is a "screensaver" you should display the message/nick somewhere

static uint8_t tick(void) {
    static uint16_t t = 0;
    t+=3;
   
    int16_t shiftLookX = LED_WIDTH * (uint32_t)sini(49 * t + 0x0fff) / 0xffff;
    int16_t shiftLookY = LED_HEIGHT * (uint32_t)sini(31 * t + 0x0fff) / 0xffff;
    uint16_t x, y;

    for(y = 0; y < LED_HEIGHT; y++) 
    {
        for(x = 0; x < LED_WIDTH; x++) 
        {
            /* TODO: delta speed from shiftLook[XY] */
            uint8_t x1 = x + shiftLookX;
            uint8_t y1 = y + shiftLookY;
            uint16_t z = getZ(x1,y1);
            uint16_t a = getA(x1,y1);
            uint32_t texel = getTex(a + t * 0x7, z + t * 2,t);
            uint8_t r = ((texel & 0xff0000) >> 16);
            uint8_t g = ((texel & 0xff00) >> 8);
            uint8_t b = (texel & 0xff);
            /* apply shade */
            uint16_t f = 0xff - MIN(0xff, z);
            r = f * r >> 8;
            g = f * g >> 8;
            b = f * b >> 8;
            
            setLedXY(x, y, r, g, b);
        }
    }

    return 0;
}

static void constructor(void) CONSTRUCTOR_ATTRIBUTES
void constructor(void) {
    registerAnimation(init,tick,deinit, 4, 1000);
}



