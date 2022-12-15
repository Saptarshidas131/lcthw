#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug()
{
    // notice you don't need the \n
    debug("I have Brown Hair");
    
    // passing in arguments like printf
    debug("I am %d years old.", 37);
}

void test_log_warn()
{
    log_err("I believe everything is broken.");
    log_err("There are %d problems in %s", 0, "space");
}

void test_log_info()
{
    log_info("Well I did something mundane.");
    log_info("It happened %f times today.", 1.3f);
}


