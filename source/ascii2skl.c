
/*******************************************************************************
 * Copyright (c) 2010, Romain Ruetschi <romain.ruetschi@gmail.com>
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @file        ascii2skl.c
 * @copyright   2010, Romain Ruetschi <romain.ruetschi@gmail.com>
 * @abstract    ASCII2SKL main file.
 */

/* System includes */
#include <stdlib.h>
#include <stdio.h>

/* Disable ASCII2SKL debugging */
#define ASCII2SKL_NO_DEBUG

/* ASCII2SKL includes */
#include "ascii2skl.h"

int main( int argc, char * argv[] )
{                        
    long                          count       = 0;
    long                          size        = 0;
    char                          current     = 0;
    char                          last        = -1;
    FILE                        * file        = NULL;
    
    if( argc < 2 )
    {
        ASCII2SKL_USAGE( argv[ 0 ] );
    }
    
    file = fopen( argv[ 1 ], "rt" );
    
    if( file == NULL )
    {
        ASCII2SKL_ERROR( "File '%s' cannot be opened.", argv[ 1 ] );
    }
    
    fseek( file, 0 , SEEK_END );
    size = ftell( file );
    rewind( file );
    flockfile( file );
    
    printf( "\n" ASCII2SKL_VERSION, size + 5 );
    printf( "\n" ASCII2SKL_HEADER() );
    
    do
    {
        current = getc_unlocked( file );
        
        if( ferror_unlocked( file ) )
        {
            ASCII2SKL_ERROR( "An error occured during reading the file.", NULL );
        }
        
        if( current != last || feof( file ) )
        {
            if( last != -1 )
            {
                ascii2skl_print_skl_char( last, count );
            }
            else if( current == EOF )
            {
                break;
            }
            
            last  = current;
            count = 1;
        }
        else
        {
            count++;
        }
    }
    while( true );
    
    printf( ASCII2SKL_FOOTER() "\n\n" );
    
    funlockfile( file );
    fclose( file );
    
    return EXIT_SUCCESS;
}

/*!
 * @function    ascii2skl_print_skl
 * @abstract    Print a single `character` `count` times in SKL.
 * @param       char    character   The character to print.
 * @param       long    count       The number of times to repeat it.
 */
void ascii2skl_print_skl_char( char character, long count )
{
    static char skl[ 20 ];
    
    switch( character )
    {
        case ' ':
            sprintf( skl, ASCII2SKL_EOS_SKL_READ );
        break;
        
        case '#':
            sprintf( skl, ASCII2SKL_EOS_SKL_WRITE );
        break;
        
        case '\n':
            sprintf( skl, ASCII2SKL_EOS_SKL_SBRK );
        break;
        
        default:
            sprintf( skl, "0%o", character );
    }
    
    while( count-- )
    {
        printf( "    " ASCII2SKL_EOS_SKL_LP ", \\\n", skl );
    }
}