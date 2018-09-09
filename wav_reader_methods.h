//
// Created by franciscohanna92 on 08/09/18.
//

#include <stdio.h>

#ifndef WAV_READER_WAV_READER_H
#define WAV_READER_WAV_READER_H

struct riff_header read_riff_header(FILE* fp);
struct fmt_subchunk read_fmt_subchunk(FILE* fp);
struct data_subchunk read_data_subchunk(FILE* fp);
void print_wav_header(struct wav_header wh);
void print_wav_header_json(struct wav_header wh);

#endif //WAV_READER_WAV_READER_H
