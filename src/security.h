#ifndef SECURITY_H
#define SECURITY_H


extern bool initialized;
//Sets up internal state. Must be called before any other calls
extern void init();

//Gets if library is initialized
extern bool isInitialized();

//Updates internal state.
extern bool update();

extern void update_perception();
extern void update_gps();
extern void update_speed();


#endif
