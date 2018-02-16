#ifndef SECURITY_H
#define SECURITY_H


static bool initialized = false;
//Sets up internal state. Must be called before any other calls
extern void init();

//Gets if library is initialized
extern bool isInitialized();

//Updates internal state.
extern bool update();


#endif
