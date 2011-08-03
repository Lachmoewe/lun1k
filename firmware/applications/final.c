#include <sysinit.h>

#include "basic/basic.h"

#include "lcd/print.h"

#include <string.h>

#include "basic/ecc.h"

/**************************************************************************/

#include "final.gen"

void init_nick();
void fancyNickname();

#include "lcd/allfonts.h"
void forLoadables(int i){
    if(i){
        lcdSetPixel(0,0);
        font=&Font_Invaders;
        ECIES_encyptkeygen(0,0,0,0,0,0);
        systickGetTicks();
        ECIES_embedded_public_key_validation();
        point_copy(0,0,0,0);
        point_is_zero(0,0);
        bitstr_parse_export(0,0);
        nrf_rcv_pkt_time_encr();
    };
};

void main_final(void) {
    //checkFirstBoot();
    init_final();
    forLoadables(0);
    menuflags|=MENU_TIMEOUT;

    while(1){
#ifndef FINAL
        if(getInputRaw()==BTN_LEFT)
            ISPandReset();
#endif
        if(getInput()){
            handleMenu(&mainmenu);
            getInputWaitRelease();
            init_nick();
        };
        work_queue();
        fancyNickname();
    };
};

void tick_final(void);
