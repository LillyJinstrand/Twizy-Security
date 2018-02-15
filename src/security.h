#ifndef SECURITY_H
#define SECURITY_H


static bool initialized = false;
//Sets up internal state. Must be called before any other calls
void init();

//Gets if library is initialized
bool isInitialized();

//Updates internal state.
bool update();


#endif
