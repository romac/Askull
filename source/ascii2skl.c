
 /*
 * Copyright (c) 2010, Romain Ruetschi <romain.ruetschi@gmail.com>
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 *  -   Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *  -   Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *  -   Neither the name of 'Jean-David Gadina' nor the names of its
 *      contributors may be used to endorse or promote products derived from
 *      this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
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