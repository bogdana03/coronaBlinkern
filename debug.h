  #ifndef DEBUGH
  #define DEBUGH
  #define DEBUGON
  #ifdef DEBUGON
#define DEBUG(msg) printf("DEBAG: %s\n", msg)
#else
#define DEBUG(msg)
#endif //DEBUGON 

#endif//DEBUGH