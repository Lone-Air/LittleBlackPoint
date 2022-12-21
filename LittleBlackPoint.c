/*
 * LMFS Games
 */
#include <stdio.h>
#include <locale.h>
#include <ncurses.h>
#include <unistd.h>

#include "pcm-player/player.h"

#define BIT_ PA_SAMPLE_S16LE

int _Play(char* src, int r, int c, int b){
   pid_t pid=fork();
   switch(pid){
     case 0:
       Play(src, r, c ,b);
       exit(0);
   }
}

int _play(char* src){
   pid_t pid=fork();
   switch(pid){
     case 0:
       play(src);
       exit(0);
   }
}

int main(){
    setlocale(LC_ALL,"");
    initscr();
    noecho();
    char k1,k2,ch;
    while(1){
        clear();
        refresh();
        ch=getch();
        if(ch=='\0'||ch=='\n') continue;
        if(ch=='m'&&k1=='g'){
            _Play("./resources/7.wav", 48000, 2, BIT_);
            k2='\0';
            k1='\0';
            ch='\0';clear();refresh();
            continue;
        }
        if(ch=='n'&&k1!='j'){
            _Play("./resources/5.wav", 48000, 2, BIT_);
            k2='n';
            ch='\0';clear();refresh();
            continue;
        }
        if(ch=='t'&&k1=='c'){
            _Play("./resources/10.wav", 48000, 2, BIT_);
            k2='t';
            ch='\0';clear();refresh();
            continue;
        }
        switch(ch){
          case 'j':
            _Play("./resources/1.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'n':
            _Play("./resources/2.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 't':
            _Play("./resources/3.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'm':
            _Play("./resources/4.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'q':
            clear();refresh();
            goto end;
            break;
          case 'g':
            _Play("./resources/6.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'c':
            _Play("./resources/9.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'r':
            _Play("./resources/11.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          case 'l':
            _Play("./resources/12.wav", 48000, 2, BIT_);
            k1=ch;
            break;
          default:
            _play("./resources/8.wav");
            k1=ch;
            break;
        }
        ch='\0';clear();refresh();
        continue;
    }
end:
    echo();
    endwin();
}

