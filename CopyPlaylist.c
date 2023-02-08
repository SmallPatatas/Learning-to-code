//a program to copy the files listed in an exported playlist to my phone,
//because to sync features never seem to work properly.

//This will scrape a Rhythmbox m3u playlist for files and create file links in a sync folder so that my
//phone can sync using Syncthing.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int source_path_check(char *source_path, int source_path_length, char *buff, int curr_position);
int subpath_and_filename_length(char *buff, int curr_position, int source_path_length);
int find_subpath_endpos(char *subpath_and_filename_string, int subpath_and_filename_string_length);

int main(int argc, char *argv[])
{
    if (argc == 1 || argv[1] == NULL)
    {
        printf("invalid number of arguments. Use \"./playlistsync --help\" for more info");
        return 0;
    }
    char *help1 = "--help";
    char *help2 = "-h";

    //provide usage help
    if (strcmp(argv[1], help1) == 0 || strcmp(argv[1], help2) == 0)
    {
        printf("\n\nUsage:\n\n      \"./playlistsync <inputfile.m3u> <SourcePath> <DestinationPath> \n\n<inputfile.m3u> is an .m3u playlist in the same folder as this program,\n<SourcePath> is the top-level directory of your music storage, and\n<DestinationPath> is the top-level folder that will be synced by Syncthing.\n");
        return 0;
    }

    if (argc < 3 || argc > 4)
    {
        printf("usage: ./playlistsync <playlist> <source> <destination> <option>\nrun \"./playlistsync -h or --help\" for help\n");
        return 0;
    }

    int counter = 0;

    FILE *playlist_ptr = fopen(argv[1], "r");     //open playlist file and make sure it is OK

    if (playlist_ptr == NULL)
    {
        printf("Invalid playlist file.\n");
        return 2;
    }
    
    fseek(playlist_ptr, 0, SEEK_END);         //get length of playlist file, use for buffer malloc
    int FILE_SIZE = ftell(playlist_ptr);
    int SourcePathLength = strlen(argv[2]);
    char *buffer = malloc(FILE_SIZE);
    if (buffer == NULL)
    {
        printf("Error reading playlist file, or out of memory.\n");
        return 3;
    }

    fseek(playlist_ptr, 0, SEEK_SET);

    fread(buffer, 1, FILE_SIZE, playlist_ptr);

    for (int i = 0; i < FILE_SIZE - SourcePathLength; i++)    //MAIN LOOP: scan through playlist buffer and grab paths and names
    {
        if (buffer[i] == '\n')
        {
            //make sure that leading characters of sourcefilepath match argv[2]
            if (source_path_check(argv[2], SourcePathLength, buffer, i) == 0)
            {
                int substring_length = subpath_and_filename_length(buffer, i, SourcePathLength);

                //get string with lower-level filepath AND filename
                char subpath_and_filename[512];
                for (int j = 0; j < substring_length; j++)
                {
                    subpath_and_filename[j] = buffer[i + SourcePathLength + j + 1];
                }
                subpath_and_filename[substring_length - 1] = '\0'; //append NUL
                
                //Create string of lower-level filepath WITHOUT filename
                int subpath_length = find_subpath_endpos(subpath_and_filename, substring_length);
                char subpath_only[256];
                for (int k = 0; k < subpath_length; k++)
                {
                    subpath_only[k] = subpath_and_filename[k];
                }
                subpath_only[subpath_length] = '\0'; // append NUL
                
                //build mkdir command
                int full_outpath_length = (strlen(argv[3]) + strlen(subpath_only/*-1? -2?*/));
                char dir_maker[267];
                sprintf(dir_maker, "mkdir -p \"%s%s\"", argv[3], subpath_only);               

                //run system(mkdir) command
                system(dir_maker);

                //make strings for hardlink creation
                char full_in[512];
                sprintf(full_in, "%s%s", argv[2], subpath_and_filename);

                char full_out[512];
                sprintf(full_out, "%s%s", argv[3], subpath_and_filename);
                printf("%s\n", full_out);
                
                //create filesystem hardlinks to audio files
                link(full_in, full_out);
                counter++;
            }
        }
    }
    //tidy up
    printf("\n%i files processed.\n", counter);
    fclose(playlist_ptr);
    free(buffer);
    return 0;

}

//checks if characters following \n match source path (argv[2])
int source_path_check(char *source_path, int source_path_length, char *buff, int curr_position)
{
    for (int i = 0; i < source_path_length; i++)
    {
        if (source_path[i] != buff[curr_position + i + 1])
        {
            return 1;
        }
    }
    return 0;
}

//finds length of subpath+filename string
int subpath_and_filename_length(char *buff, int curr_position, int source_path_length)
{
    int length = 0;
    while (buff[curr_position + source_path_length + length] != '\n')
    {
        length++;
    }
    return length;
}

//find end of directory structure / start of filename
int find_subpath_endpos(char *subpath_and_filename_string, int subpath_and_filename_string_length)
{
    int n = subpath_and_filename_string_length;
    for (int n = subpath_and_filename_string_length; n > 0; n--)
    {
        if (subpath_and_filename_string[n] == '/')
        {
            n++;
            return n;
        }
    }
    return 0;
}
