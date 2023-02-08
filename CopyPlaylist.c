#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    const char *help1 = "--help";
    const char *help2 = "-h";

    //provide usage help
    if (strcmp(argv[1], help1) || strcmp(argv[1], help2))
    {
        printf("usage: \"./playlistsync <inputfile> <source> <destination> <-s/-h>\"\n\n
        where <inputfile is an xspf playlist in the same folder
        as this program, source is the top-level of your music storage, and the destination
        is the top-level folder that is being synced by syncthing.\n\n
        This program does not make a copy of the files themselves, it
        only adds a symbolic link or hardlink.\n\n
        Filesystem must be ext4 or NTFS, and the two locations must exist on
        the same partition.\n\n
        WARNING: if symbolic link is chosen with the argument -s, then deleting the
        original file will cause the link to no longer work.")
        return 0;
    }

    if (argc < 3 || argc > 4)
    {
        printf("usage: ./playlistsync <playlist> <destination> <option>\n
        run \"./playlistsync -h\" for help\n")
        return 1;
    }

    //open playlist file and make sure it is OK
    FILE *playlist_ptr = fopen(argv[1], "r");

    if (playlist_ptr == NULL)
    {
        printf("Invalid playlist file.\n")
        return 2;
    }



    //a program to copy the files listed in an exported playlist to my phone,
    //because to sync features never seem to work properly.

    //need to decide which playlist format: probably xspf easiest to scrape
    //but m3u is also likely to work well


    //take arguments: playlist file, output folder
    //verify playlist filetype
    //verify # of arguments and validity of arguments


    //load playlist file
    //scrape filepaths/names:
    //read (by char?) (use fseek or fgetc?) file, find filepaths/names,
    //convert characters as necessary eg '%20' to '\ ' possibly? Other special characters??

    //strip leading chars?
    //copy filepaths/names into array OR write to file?
    //(can I dynamically allocate array memory based on the
    //length of the actual filepath/name?)


            //scan playlist and use counter to find total number of [tracks]
            //scrape portions of path/name etc into struct with [tracks] number of elements
            //then use system() calls to do terminal commands:
            //check if output (hard link or symbolic link?) file exists
            //***is there a way to ckeck if a directory exists?
            //if file doesn't exist, add one to a counter, print # of tracks need to create links for

            //create directory for file, then create link (hard or symbolic??)
            //otherwise go to next element in struct array

    //could have "album mode" but probably not necessary or more useful

    //copy files to output folder:
    //strip leading chars?
    //prepend folder location (argv[?]) to filepath/names



    //if file already exists then ask to skip, overwrite, overwrite all or skip all
    //do I need to check free space first?
    //report # of files copied out of # in playlist?
    //


}
