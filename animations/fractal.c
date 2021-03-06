#include <stdlib.h>
#include "main.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "libs/armmath.h"
#include "libs/text.h"

uint8_t MAXITER=50;   //150 works well for our maximum zoomlevel
#define RADIUS 4
#define ZOOMSPEED 0.99
#define INTERESTINGPOINTS 4




static float Maxx;             // Rightmost Real point of plane to be displayed
static float Minx;            // Leftmost Real point
static float Maxy;             // Uppermost Imaginary point
static float Miny;            // Lowermost Imaginary point
static uint8_t PoI_num;
static uint32_t zoomlevel;
static float PoI[INTERESTINGPOINTS][2]={
	{-1.7864402559762,0},
	{-0.74977879167273,0.061208886981615},
	{-0.10065324543004,0.95635515294465},
	{-1.2539214922673,-0.38266971143805},
};
float dx=0;
float dy=0;

static int colors[15][3] = {
	{0,0,255},
	{0,139,0},
	{0,255,255},
	{255,0,0},
	{255,0,255},
	{165,42,42},
	{240,240,240},
	{190,190,190},
	{173,216,230},
	{0,255,0},
	{224,255,255},
	{255,192,203},
	{139,0,139},
	{255,255,0},
	{255,255,255}
};

static void init(void) {
	Maxx = 0.5;
	Minx = -2;
	Maxy = 1.25;
	Miny = -1.25;
	zoomlevel = 0;
	//srand(time(NULL));
	PoI_num = rand() % INTERESTINGPOINTS;
}
static uint8_t getIter(uint8_t xin, uint8_t yin) {
	float x=0;
	float y=0;		
	float xnew=0;
	uint8_t k=0;
	float offsetx = xin*dx+Minx;
	float offsety = Maxy-yin*dy;
    
    float xsqrd = 0;
    float ysqrd = 0;
    
	while( k <= MAXITER ) {
		xnew= xsqrd - ysqrd + offsetx;
		y = 2*x*y + offsety;
		x = xnew;
        xsqrd = x*x; //can the f4 do x*x+y*y in one step??? 
        ysqrd = y*y; //if not, this is 4 clocks faster per iteration...
		k++;
		if ( (xsqrd+ysqrd) > RADIUS ) break; 
	} 
	return k;
}
static uint8_t tick(void) {
				
	if (zoomlevel > 1100) {
		init();
	}

	MAXITER = (zoomlevel/7) + 20;
	dx = (Maxx-Minx)/LED_HEIGHT;
	dy = (Maxy-Miny)/LED_WIDTH;

	//time_t start = clock();

	uint8_t color;
	uint8_t x,y,r,g,b;

	for(y = 0; y < LED_HEIGHT; y++) {
		for(x = 0; x < LED_WIDTH; x++) {
			color =	getIter(x,y);
			if (color>MAXITER) {
				r=0;
				g=0;
				b=0;
			} else {
				color=(color+zoomlevel)%15;
				r=colors[color][0];
				g=colors[color][1];
				b=colors[color][2];
			} 
			setLedXY(x,y,r,g,b);
		}
	}
	Maxx = Maxx*ZOOMSPEED + PoI[PoI_num][0]*(1-ZOOMSPEED);
	Minx = Minx*ZOOMSPEED + PoI[PoI_num][0]*(1-ZOOMSPEED);
	Maxy = Maxy*ZOOMSPEED + PoI[PoI_num][1]*(1-ZOOMSPEED);
	Miny = Miny*ZOOMSPEED + PoI[PoI_num][1]*(1-ZOOMSPEED);
                
	//printf("Zoomlevel: %d\t",zoomlevel++);
	//printf("MAXITER: %d\t",MAXITER);
                
	//time_t end=clock();
	//printf("Rechenzeit: %ld\n",(end-start));
  draw_number_8x6(3,3,zoomlevel,4,' ',0,0,0);             
  draw_number_8x6(2,2,zoomlevel,4,' ',255,255,255);             
	zoomlevel++;
	return 0;
}




static void deinit(void)
{
}



static void constructor(void) CONSTRUCTOR_ATTRIBUTES
void constructor(void) {
	registerAnimation(init,tick,deinit, 4, 1232); 
}




