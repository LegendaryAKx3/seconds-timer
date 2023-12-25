#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <argp.h>

const char *argp_program_version =
  "timer 1.0";

static char doc[] =
  "timer -- timer exclusively using seconds";

static struct argp argp = { 0, 0, doc };


int main(int argc, char** argv) {
    argp_parse (&argp, argc, argv, 0, 0, 0);
    exit(0);
}