#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>

#define PSIZEX 10
#define PSIZEY 10

#define FONTX 3
#define FONTY 5

#define CHARW (PSIZEX*FONTX)
#define CHARH (PSIZEY*FONTY)

#define C(x,r,g,b)	SDL_MapRGB(x->format, r, g, b)

int fonte[165] = 
{ 
	1,1,1,
	1,0,1,
	1,0,1,
	1,0,1,
	1,1,1,

	0,0,1, 
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,

	1,1,1,
	0,0,1,
	1,1,1,
	1,0,0,
	1,1,1,

	1,1,1,
	0,0,1,
	1,1,1,
	0,0,1,
	1,1,1,

	1,0,1,
	1,0,1,
	1,1,1,
	0,0,1,
	0,0,1,

	1,1,1,
	1,0,0,
	1,1,1,
	0,0,1,
	1,1,1,

	1,0,0,
	1,0,0,
	1,1,1,
	1,0,1,
	1,1,1,

	1,1,1,
	0,0,1,
	0,0,1,
	0,0,1,
	0,0,1,

	1,1,1,
	1,0,1,
	1,1,1,
	1,0,1,
	1,1,1,

	1,1,1,
	1,0,1,
	1,1,1,
	0,0,1,
	0,0,1,

	1,1,1,
	0,0,1,
	0,1,0,
	0,0,0,
	0,1,0
};

SDL_Surface *plotnumber(int n) {
	SDL_Surface *retval;
	SDL_Rect drawrect;
	int i ;
	if(n > 10) n = 10;
	retval = SDL_CreateRGBSurface(SDL_SWSURFACE, CHARW, CHARH, 16, 0, 0, 0, 0);
	for ( i = (n*15) ;  i < ((n+1)*15) ; i++ ) {
			if (fonte[i] == 1) {
				drawrect.x = (i%3)*PSIZEX;
				drawrect.y = ((i/3)%5)*PSIZEY;
				drawrect.w = PSIZEX;
				drawrect.h = PSIZEY;
				SDL_FillRect(retval, &drawrect, SDL_MapRGB( retval->format, 255, 0, 0));
			}
	}
	
	return retval;
}

SDL_Surface *plotlongnumber(unsigned int n) {
	SDL_Surface *retval;
	
	char string[30];
        int i, len = 0;

        len = snprintf(string, sizeof(char)*30 ,"%u", n);

	retval = SDL_CreateRGBSurface(SDL_SWSURFACE, (CHARW+3)*len, CHARH, 16, 0, 0, 0, 0);

        for(i = 0; i < len; i++) {
		SDL_Surface *temp;        
		SDL_Rect drawrect;
		char ch[2];

		ch[0] = string[i];
		ch[1] = '\0';
		temp = plotnumber(atoi(ch));
		drawrect.x = (CHARW+3)*i;
		drawrect.y = 0;
		SDL_BlitSurface(temp, NULL, retval, &drawrect);
		SDL_FreeSurface(temp);
	}

	return retval;

}


