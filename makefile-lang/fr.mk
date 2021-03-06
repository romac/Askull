# ------------------------------------------------------------------------------
# 
# Copyright (c) 2010, Jean-David Gadina <macmade@eosgarden.com>
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
# 
#  -   Redistributions of source code must retain the above copyright notice,
#      this list of conditions and the following disclaimer.
#  -   Redistributions in binary form must reproduce the above copyright
#      notice, this list of conditions and the following disclaimer in the
#      documentation and/or other materials provided with the distribution.
#  -   Neither the name of 'Jean-David Gadina' nor the names of its
#      contributors may be used to endorse or promote products derived from
#      this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 
# ------------------------------------------------------------------------------
# 
# IMPORTANT NOTE:
# 
# This makefile contains the language labels for the main makefile.
# It's not supposed to be called directly by the make command.
# 
# Words in uppercase beginning end ending with a '_' are placeholders for
# dynamic variables and will be substituded during the make process. Do not
# translated them. Also remember that you have to escape special characters
# with a backslash.
# 
# Please note that you need at least version 3.81 of GNU Make to use this file.
# Older versions are not supported and will never be.
# 
# You also need a copy of the GNU Libtool in order to handle the shared objects.
# GNU Libtool is sometimes called glibtool, or simply libtool.
# Others implementations of Libtool are not supported at the time.
# 
#-------------------------------------------------------------------------------

# $Id: fr.mk 2 2010-06-27 10:25:10Z macmade@eosgarden.com $

# Flag to let the makefile knows that the language labels were included
LANG_HASLABELS           := 1

# Language labels
LANG_MAKESTART           := Début du script make
LANG_MAKEVERSION_NEEDED  := Version de GNU Make requise: _VERSION_
LANG_MAKEVERSION_CURRENT := Version actuelle de GNU Make: _VERSION_
LANG_MAKEEND             := Fin du script make
LANG_THANX               := Merci d\'avoir utilisé ce makefile
LANG_GOODBYE             := Bonne journée
LANG_DONE                := Terminé
LANG_LIB_START           := Recherche et génération des librairies
LANG_LIB_END             := Toutes les librairies ont été traités
LANG_SO_START            := Recherche et génération des objets partagés
LANG_SO_END              := Tous les objects partagés ont été traités
LANG_EXEC_START          := Recherche et génération des exécutables
LANG_EXEC_END            := Tous les exécutables ont été traités
LANG_CLEAN_START         := Effacement des fichiers générés dans _DIR_BUILD_
LANG_NOSCRIPT_UNINSTALL  := Désolé, mais il n\'y a actuellement aucun script de désinstallation
LANG_NOSCRIPT_TEST       := Désolé, mais il n\'y a actuellement aucun script de test
LANG_NOSCRIPT_INFOS      := Vous devriez trouver les fichiers générés et les binaires dans _DIR_BUILD_
LANG_O_BUILD             := Génération du fichier objet pour _CFILE_ dans _DIR_BUILD_
LANG_LO_BUILD            := Génération du fichier objet de librairie pour _CFILE_ dans _DIR_BUILD_
LANG_LA_BUILD            := Génération du fichier archive de librairie pour _TNAME_ dans _DIR_BUILD_
LANG_DEPS_FIND           := Recherche des dépendances pour _TFILE_
LANG_DEPS_NODEPS         := _TFILE_ ne dépend d\'aucun objet partagé
LANG_OUT_BUILD           := Génération du fichier de sortie pour _CFILE_ dans _DIR_BUILD_
LANG_EXEC_BUILD_HASDEPS  := Génération de l\'exécutable _TFILE_ dans _DIR_BUILD_ en liant _OFILE_ avec ses dépendances: _DEPS_
LANG_EXEC_BUILD_NODEPS   := Génération de l\'exécutable _TFILE_ pour _CFILE_ dans _DIR_BUILD_
LANG_INSTALL_BIN         := Installation des exécutables dans _PREFIX_
