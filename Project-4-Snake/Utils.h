#ifndef __UTILS_H__
#define __UTILS_H__

#include "Snake.h"

// mse-evil
void LogGameStats(int turnCount, char cmd, const Snake &snake); 

// return snake length concatenated with some status message 
string Message(string status, const Snake &snake); 


#endif