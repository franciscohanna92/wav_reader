#include <stdio.h>

#include "lib/wav_reader_types.h"
#include "lib/wav_reader_methods.h"

int main(int argc, char **argv) {
    FILE *fp;

    if(argc == 2) {
        fp = fopen(argv[1], "rb");
        int isValid = check_file_format(fp);
        if(isValid == 0) {
            fp = fopen(argv[1], "rb");
            struct wav_header wh = {
                read_riff_header(fp),
                read_fmt_subchunk(fp),
                read_data_subchunk(fp),
            };

            print_wav_header(wh);
        } else {
            printf("The specified file is not a valid WAVE file.");
        }

        fclose(fp);
    } else {
        printf("You must specify only one argument that must be the relative path to a WAV file.");
    }
    return 0;
}