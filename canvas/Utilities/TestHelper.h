#ifndef canvas_Utilities_TestHelper_h
#define canvas_Utilities_TestHelper_h
// -*- C++ -*-

//------------------------------------------------------------
//
// Function to drive test programs and scripts.
//
// Write your test program with whatever name you want; the
// implementation should be:
//
//    int main(int argc, char* argv[]) { return ptomaine(argc, argv); }
//
//
// Asumming you call your program RunThis, invocation of this program
// should look like:
//
//   RunThis <shell name> <command> [args ...]
// e.g.
//   RunThis /bin/bash ls
//   RunThis /bin/bash fw -p somefile.cfg
//   RunThis /bin/bash some_script.sh a b c
//
//
//
//------------------------------------------------------------

int ptomaine(int argc, char* argv[], char** env);

#define RUNTEST() extern "C" char** environ; int main(int argc, char* argv[]) { return ptomaine(argc, argv, environ); }

#endif /* canvas_Utilities_TestHelper_h */

// Local Variables:
// mode: c++
// End:
