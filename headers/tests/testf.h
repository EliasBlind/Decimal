#ifndef TESTF_H
#define TESTF_H

#ifdef TEST 
#define LOG_ERROR(message) do { \
    fprintf(stderr, "File: %s, string: %d: %s\n", __FILE__, __LINE__, message); \
    exit(EXIT_FAILURE); \
} while (0)
#endif // TEST

#endif // TESTF_H