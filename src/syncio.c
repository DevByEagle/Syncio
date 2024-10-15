#include <stdio.h>
#include <unistd.h>

#include "../include/syncio.h"

void delay(unsigned int ms) {
    sleep(ms);
}