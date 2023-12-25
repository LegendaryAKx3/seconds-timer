#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <argp.h>

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
        // TODO: timer
    } else {
        fprintf(stderr, "Error: Invalid value for SECONDS\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}