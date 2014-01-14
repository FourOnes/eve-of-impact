/*
 *  MathAdditional.h
 *  Eve of Impact
 *
 *  Created by Rik Schennink on 4/16/10.
 *  Copyright 2010 Rik Schennink. All rights reserved.
 *
 */

#define TRIG_PI			 3.141592 // PI
#define TRIG_PI_M_2		 6.283185 // PI * 2
#define TRIG_PI_D_2		 1.570796 // PI / 2
#define TRIG_PI_D_180	 0.017453 // PI / 180
#define TRIG_180_D_PI	 57.29577 // 180 / PI
#define TRIG_PI_M_1_360  0.008727 // PI * (1/360)

#define ARC4RANDOM_MAX	0x100000000

static uint uniqueId = 1000;

static inline float mathRandom() {
	return (double)arc4random() / ARC4RANDOM_MAX;
}

static inline float randomBetween(float bottom, float top) {
	return bottom + mathRandom() * (top - bottom);
}

static inline float sinHash(uint angle) {
	
	static const float table[360] = {
		0.000000,0.017452,0.034899,0.052336,0.069756,0.087156,0.104528,0.121869,0.139173,0.156434,0.173648,0.190809,0.207912,0.224951,0.241922,0.258819,0.275637,0.292372,0.309017,0.325568,0.342020,0.358368,0.374607,0.390731,0.406737,0.422618,0.438371,0.453991,0.469472,0.484810,0.500000,0.515038,0.529919,0.544639,0.559193,0.573576,0.587785,0.601815,0.615662,0.629320,0.642788,0.656059,0.669131,0.681998,0.694658,0.707107,0.719340,0.731354,0.743145,0.754710,0.766044,0.777146,0.788011,0.798635,0.809017,0.819152,0.829038,0.838671,0.848048,0.857167,0.866025,0.874620,0.882948,0.891006,0.898794,0.906308,0.913545,0.920505,0.927184,0.933580,0.939693,0.945519,0.951057,0.956305,0.961262,0.965926,0.970296,0.974370,0.978148,0.981627,0.984808,0.987688,0.990268,0.992546,0.994522,0.996195,0.997564,0.998630,0.999391,0.999848,1.000000,0.999848,0.999391,0.998630,0.997564,0.996195,0.994522,0.992546,0.990268,0.987688,0.984808,0.981627,0.978148,0.974370,0.970296,0.965926,0.961262,0.956305,0.951056,0.945519,0.939693,0.933580,0.927184,0.920505,0.913545,0.906308,0.898794,0.891006,0.882948,0.874620,0.866025,0.857167,0.848048,0.838671,0.829038,0.819152,0.809017,0.798635,0.788011,0.777146,0.766044,0.754710,0.743145,0.731354,0.719340,0.707107,0.694658,0.681998,0.669131,0.656059,0.642788,0.629321,0.615661,0.601815,0.587785,0.573576,0.559193,0.544639,0.529919,0.515038,0.500000,0.484810,0.469472,0.453991,0.438371,0.422618,0.406737,0.390731,0.374606,0.358368,0.342020,0.325568,0.309017,0.292372,0.275637,0.258819,0.241922,0.224951,0.207912,0.190809,0.173648,0.156434,0.139173,0.121869,0.104529,0.087156,0.069756,0.052336,0.034899,0.017452,-0.000000,-0.017452,-0.034899,-0.052336,-0.069756,-0.087156,-0.104528,-0.121869,-0.139173,-0.156434,-0.173648,-0.190809,-0.207912,-0.224951,-0.241922,-0.258819,-0.275637,-0.292372,-0.309017,-0.325568,-0.342020,-0.358368,-0.374607,-0.390731,-0.406737,-0.422618,-0.438371,-0.453991,-0.469472,-0.484810,-0.500000,-0.515038,-0.529919,-0.544639,-0.559193,-0.573576,-0.587785,-0.601815,-0.615661,-0.629320,-0.642788,-0.656059,-0.669131,-0.681998,-0.694658,-0.707107,-0.719340,-0.731354,-0.743145,-0.754710,-0.766045,-0.777146,-0.788011,-0.798635,-0.809017,-0.819152,-0.829038,-0.838670,-0.848048,-0.857167,-0.866025,-0.874620,-0.882948,-0.891006,-0.898794,-0.906308,-0.913545,-0.920505,-0.927184,-0.933580,-0.939693,-0.945519,-0.951056,-0.956305,-0.961262,-0.965926,-0.970296,-0.974370,-0.978148,-0.981627,-0.984808,-0.987688,-0.990268,-0.992546,-0.994522,-0.996195,-0.997564,-0.998630,-0.999391,-0.999848,-1.000000,-0.999848,-0.999391,-0.998630,-0.997564,-0.996195,-0.994522,-0.992546,-0.990268,-0.987688,-0.984808,-0.981627,-0.978148,-0.974370,-0.970296,-0.965926,-0.961262,-0.956305,-0.951056,-0.945519,-0.939693,-0.933580,-0.927184,-0.920505,-0.913545,-0.906308,-0.898794,-0.891006,-0.882948,-0.874620,-0.866025,-0.857167,-0.848048,-0.838670,-0.829038,-0.819152,-0.809017,-0.798635,-0.788011,-0.777146,-0.766044,-0.754710,-0.743145,-0.731354,-0.719340,-0.707107,-0.694658,-0.681998,-0.669131,-0.656059,-0.642788,-0.629320,-0.615661,-0.601815,-0.587785,-0.573577,-0.559193,-0.544639,-0.529919,-0.515038,-0.500000,-0.484809,-0.469472,-0.453991,-0.438371,-0.422618,-0.406736,-0.390731,-0.374607,-0.358368,-0.342020,-0.325568,-0.309017,-0.292372,-0.275638,-0.258819,-0.241922,-0.224951,-0.207912,-0.190809,-0.173648,-0.156434,-0.139173,-0.121869,-0.104529,-0.087156,-0.069756,-0.052336,-0.034900,-0.017453
	};
	
	if (angle>=360) {
		angle = angle%360;
	}
	
	return table[angle];
}

static inline float cosHash(uint angle) {
	return sinHash(angle+270);
}

static inline float invSqrt( float x ) {
    float xhalf = 0.5f*x;
    int i = *(int*)&x;
    i = 0x5f3759df - (i>>1);
    x = *(float*)&i;
    x = x*(1.5f - xhalf*x*x);
    return x;
}

static inline uint getUniqueId() {
	return uniqueId++;
}

static inline float getDistanceSquaredToPlanet(float x,float y) {
	return x*x + y*y;
}

static inline float getDistanceSquaredBetween(float x1,float y1,float x2, float y2) {
	float dx,dy;
	dx = x2 - x1;
	dy = y2 - y1;
	return dx * dx + dy * dy;
}

