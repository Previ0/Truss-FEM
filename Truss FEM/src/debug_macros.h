#ifndef DEBUG_MACROS_H
#define DEBUG_MACROS_H

// DEBUG MESSAGE
#if PR_DEBUG==1
#define DEBUG_MESSAGE(type, message) std::cout <<"[ "<< #type << " ] : " << message << std::endl
#elif defined(PR_RELEASE)
#define DEBUG_MESSAGE(type, message)
#endif // PR_DEBUG 1

#endif // !DEBUG_MACROS_H