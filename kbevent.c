/*
 * LMFS Games - Keyboard Event
 */

#include "kbevent.h"

void t_lnbuf(int yn) {
   struct termios oldt, newt;
   tcgetattr(0, &oldt);
   newt = oldt;
   if (!yn) newt.c_lflag &= ~ICANON;
   else newt.c_lflag |= ICANON;
   tcsetattr(0, TCSANOW, &newt);
}

void t_echo(int yn) {
   struct termios oldt, newt;
   tcgetattr(0, &oldt);
   newt = oldt;
   if (!yn) newt.c_lflag &= ~ECHO;
   else newt.c_lflag |= ECHO;
   tcsetattr(0, TCSANOW, &newt);
}


int getch() {
   register int ch;
   t_lnbuf(0);
   t_echo(0);
   ch = getchar();
   t_lnbuf(1);
   t_echo(1);
   return ch;
}

int kbhit() {
   register int ret;
   fd_set fds;
   t_lnbuf(0);
   t_echo(0);
   struct timeval tv;
   tv.tv_sec = 0;
   tv.tv_usec = 0;
   FD_ZERO(&fds);
   FD_SET(0, &fds);
   select(1, &fds, 0, 0, &tv);
   ret = FD_ISSET(0, &fds);
   t_lnbuf(1);
   t_echo(1);
   return ret;
}

