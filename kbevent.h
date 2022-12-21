/* 
 * LMFS Games - Keyboard Event
 */
#ifndef _KBEVENT_H
#define _KBEVENT_H

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

void t_lnbuf(int yn);
void t_echo(int yn);

int getch();
int kbhit();

#endif
