#include <stdio.h>

#include "wav_reader_types.h"
#include "wav_reader_methods.h"

int main() {
    FILE *fp;
    fp = fopen("../resources/PCM_16bits_44100Hz_stereo.wav", "rb");

    struct wav_header wh = {
        read_riff_header(fp),
        read_fmt_subchunk(fp),
        read_data_subchunk(fp),
    };

    print_wav_header(wh);
    print_wav_header_json(wh);


    fclose(fp);
    return 0;
}