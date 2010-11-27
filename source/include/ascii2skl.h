
#ifndef ASCII2SKL_H
#define ASCII2SKL_H
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

/* Definition of the boolean datatype if not enabled */
#ifndef __bool_true_false_are_defined
    #define bool                            _Bool
    #define true                            1
    #define false                           0
    #define __bool_true_false_are_defined   1
#endif

/* Holds the error message used in ASCII2SKL_ERROR() */
static char * error = NULL;

/*!
 * @define      ASCII2SKL_USAGE
 * @abstract    Outputs some informations about how to call the executable.
 * @param       The path to the current executable, typically argv[ 0 ].
 */
#define ASCII2SKL_USAGE( path ) \
    printf( "[ USAGE ] %s file\n", path ); \
    exit( EXIT_SUCCESS );

/*!
 * @define      ASCII2SKL_ERROR
 * @abstract    Outputs an error message on stderr, then exit the process.
 * @param       A message, with optional arguments for the format
 */
#define ASCII2SKL_ERROR( s, ... ) \
    asprintf( &error, "[ ERROR ] " s "\n", __VA_ARGS__ ); \
    fputs( error, stderr ); \
    exit( EXIT_FAILURE );

#ifndef ASCII2SKL_NO_DEBUG 

/*!
 * @define      ASCII2SKL_DEBUG
 * @abstract    Outputs an debug message on stdout.
 * @param       A message, with optional arguments for the format
 */
#define ASCII2SKL_DEBUG( s, ... ) \
    printf( "[ DEBUG ] " s "\n", __VA_ARGS__ );

/*!
 * @define      ASCII2SKL_DEBUG_QUIT
 * @abstract    Outputs an debug message on stdout, then exit the process.
 * @param       A message, with optional arguments for the format
 */
#define ASCII2SKL_DEBUG_QUIT( s, ... ) \
    ASCII2SKL_DEBUG( s, __VA_ARGS__ ); \
    exit( EXIT_SUCCESS );

#else

#define ASCII2SKL_DEBUG( s, ... )
#define ASCII2SKL_DEBUG_QUIT( s, ... )

#endif

#define ASCII2SKL_EOS_SKL_SBRK  "__EOS_SKL_SBRK__"
#define ASCII2SKL_EOS_SKL_READ  "__EOS_SKL_READ__"
#define ASCII2SKL_EOS_SKL_WRITE "__EOS_SKL_WRITE__"
#define ASCII2SKL_EOS_SKL_LP    "__EOS_SKL_LP01__(%s)"

#define ASCII2SKL_NAME "ARCH_I386"

#define ASCII2SKL_VERSION "#define __" ASCII2SKL_NAME "_VERSION__ 0%lo"

#define ASCII2SKL_HEADER() \
    "#define __" ASCII2SKL_NAME "_SKL__(eax,ebx,ecx,edx,esp) \\\n" \
    "    const ecx##edx##eax##ebx __header_skl_cp__[esp]={ \\\n" \
    "        __EOS_SKL_SJMP__(),__" ASCII2SKL_NAME "_SKL_MMAP(),__EOS_SKL_SJMP__() \\\n" \
    "    };\n\n" \
    "#define __" ASCII2SKL_NAME "_SKL_MMAP() \\\n" \
    "    __EOS_SKL_LP01__(" ASCII2SKL_EOS_SKL_SBRK "),\\\n"

#define ASCII2SKL_FOOTER() \
    "    __EOS_SKL_LP01__(" ASCII2SKL_EOS_SKL_SBRK ")\n" \
    "    __" ASCII2SKL_NAME "_SKL__(a,r,c,h,__" ASCII2SKL_NAME "_VERSION__)"

/*!
 * @function    ascii2skl_print_skl_char
 * @abstract    Print a single `character` `count` times in SKL.
 * @param       char    character   The character to print.
 * @param       long    count       The number of times to repeat it.
 */
void ascii2skl_print_skl_char( char character, long count );

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: ASCII2SKL_H */
