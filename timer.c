#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <argp.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int timer(int duration);
int print(int seconds);

const char *argp_program_version = "timer 1.0";

static char doc[] = "A simple timer program that only uses seconds";

static char args_doc[] = "[SECONDS]";

struct arguments {
    int seconds;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = (struct arguments *)state->input;

    switch (key) {
        case ARGP_KEY_ARG:
            if (state->arg_num == 0) {
                arguments->seconds = atoi(arg);
            } else {
                argp_usage(state);
            }
            break;

        case ARGP_KEY_END:
            if (state->arg_num != 1) {
                argp_usage(state);
            }
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp_option options[] = {
    {0}
};

static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char *argv[]) {
    struct arguments arguments;

    arguments.seconds = 0;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.seconds > 0) {
        timer(arguments.seconds);
    } else {
        fprintf(stderr, "Error: Invalid value for SECONDS\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int print(int seconds) {
    int minute = floor(seconds / 60);
    int second = seconds - (minute * 60);
    int hour = floor(minute / 60);
    minute = minute - (hour * 60);
    system("clear");
    // printf("1. Start  2. Stop  3. Reset  4. End\n");
    printf("===================================\n");
    printf("               %d:%d:%d\n", hour, minute, second); 
    printf("===================================\n");
    return (seconds - 1);
}

int timer(int duration){
  while (duration > 0) {
    #ifdef _WIN32
        Sleep( 1000 );
    #else
        sleep( 1 );
    #endif
    duration = print(duration);
    
  }
  return 0;
}