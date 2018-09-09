#include <stdio.h>
#include "wav_reader_types.h"

/**
 *
 * @param fp
 * @return
 */
struct riff_header read_riff_header(FILE* fp) {
    struct riff_header rh = {
            {0, 0, 0, 0, '\0'},
            0,
            {0, 0, 0, 0, '\0'}
    };

    fread(rh.chunk_id, 4, 1, fp);
    fread(&rh.chunk_size, 4, 1, fp);
    fread(rh.format, 4, 1, fp);

    return rh;
}

/**
 *
 * @param fp
 * @return
 */
struct fmt_subchunk read_fmt_subchunk(FILE* fp) {
    struct fmt_subchunk fs;

    fread(fs.subchunk1_id, 4, 1, fp);
    fread(&fs.subchunk1_size, 4, 1, fp);
    fread(&fs.audio_format, 2, 1, fp);
    fread(&fs.num_channels, 2, 1, fp);
    fread(&fs.sample_rate, 4, 1, fp);
    fread(&fs.byte_rate, 4, 1, fp);
    fread(&fs.block_align, 2, 1, fp);
    fread(&fs.bits_per_sample, 2, 1, fp);

    int extra_param_size;
    fread(&extra_param_size, 2, 1, fp);

    return fs;
}

/**
 *
 * @param fp
 * @return
 */
struct data_subchunk read_data_subchunk(FILE* fp) {
    struct data_subchunk ds;

    fread(ds.subchunk2_id, 4, 1, fp);
    fread(&ds.subchunk2_size, 4, 1, fp);

    return ds;
}

/**
 *
 * @param wh
 */
void print_wav_header(struct wav_header wh) {
    printf("*** RIFF Header *** \n");
    printf("%s\n", wh.riff_header.chunk_id);
    printf("%d\n", wh.riff_header.chunk_size);
    printf("%s\n\n", wh.riff_header.format);

    printf("*** fmt subchunk *** \n");
    printf("%s\n", wh.fmt_subchunk.subchunk1_id);
    printf("%d\n", wh.fmt_subchunk.subchunk1_size);
    printf("%d\n", wh.fmt_subchunk.audio_format);
    printf("%d\n", wh.fmt_subchunk.num_channels);
    printf("%d\n", wh.fmt_subchunk.sample_rate);
    printf("%d\n", wh.fmt_subchunk.byte_rate);
    printf("%d\n", wh.fmt_subchunk.block_align);
    printf("%d\n\n", wh.fmt_subchunk.bits_per_sample);

    printf("*** data subchunk ***\n");
    printf("%s\n", wh.data_subchunk.subchunk2_id);
    printf("%d\n", wh.data_subchunk.subchunk2_size);
}

/**
 *
 * @param wh
 */
void print_wav_header_json(struct wav_header wh) {
    printf("{"
           "\"riff_header\": {"
           "\"chunk_id\": \"%s\","
           "\"chunk_size\": %d,"
           "\"format\": \"%s\""
           "}", wh.riff_header.chunk_id, wh.riff_header.chunk_size, wh.riff_header.format);

//    printf("%s\n", wh.riff_header.chunk_id);
//    printf("%d\n", wh.riff_header.chunk_size);
//    printf("%s\n\n", wh.riff_header.format);
//
//    printf("*** fmt subchunk *** \n");
//    printf("%s\n", wh.fmt_subchunk.subchunk1_id);
//    printf("%d\n", wh.fmt_subchunk.subchunk1_size);
//    printf("%d\n", wh.fmt_subchunk.audio_format);
//    printf("%d\n", wh.fmt_subchunk.num_channels);
//    printf("%d\n", wh.fmt_subchunk.sample_rate);
//    printf("%d\n", wh.fmt_subchunk.byte_rate);
//    printf("%d\n", wh.fmt_subchunk.block_align);
//    printf("%d\n\n", wh.fmt_subchunk.bits_per_sample);
//
//    printf("*** data subchunk ***\n");
//    printf("%s\n", wh.data_subchunk.subchunk2_id);
//    printf("%d\n", wh.data_subchunk.subchunk2_size);
}
