#include <stdio.h>
#include <string.h>
#include "wav_reader_types.h"

/**
 * Checks if the file provided is a WAV one.
 * @param fp A pointer to a WAV file
 * @return 1 if the file is WAV one. 0 otherway.
 */
int check_file_format(FILE* fp) {
    char chunk_id[5] = {0, 0, 0, 0, '\0'};
    char RIFF[] = "RIFF";
    fread(chunk_id, 4, 1, fp);

    return strcmp(chunk_id, RIFF);
}

/**
 * Reads the RIFF header of the WAV file
 * @param fp A pointer to a WAV file
 * @return a struct representing the RIFF header
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
 * Reads the fmt subchunk of the WAV file
 * @param fp A pointer to a WAV file
 * @return a struct representing the fmt subchunk
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
 * Reads the data subchunk of the WAV file
 * @param fp A pointer to a WAV file
 * @return a struct representing the data subchunk
 */
struct data_subchunk read_data_subchunk(FILE* fp) {
    struct data_subchunk ds;

    fread(ds.subchunk2_id, 4, 1, fp);
    fread(&ds.subchunk2_size, 4, 1, fp);

    return ds;
}

/**
 *  Prints the read header from the WAV file
 * @param wh a struct representing the WAV header
 */
void print_wav_header(struct wav_header wh) {
    printf("ChunkID\t\t\t%s\n", wh.riff_header.chunk_id);
    printf("ChunkSize\t\t%d\n", wh.riff_header.chunk_size);
    printf("Format\t\t\t%s\n\n", wh.riff_header.format);

    printf("Subchunk1ID\t\t%s\n", wh.fmt_subchunk.subchunk1_id);
    printf("Subchunk1Size\t%d\n", wh.fmt_subchunk.subchunk1_size);
    printf("AudioFormat\t\t%d\n", wh.fmt_subchunk.audio_format);
    printf("NumChannels\t\t%d\n", wh.fmt_subchunk.num_channels);
    printf("SampleRate\t\t%d\n", wh.fmt_subchunk.sample_rate);
    printf("ByteRate\t\t%d\n", wh.fmt_subchunk.byte_rate);
    printf("BlockAlign\t\t%d\n", wh.fmt_subchunk.block_align);
    printf("BitsPerSample\t%d\n\n", wh.fmt_subchunk.bits_per_sample);

    printf("Subchunk2ID\t\t%s\n", wh.data_subchunk.subchunk2_id);
    printf("Subchunk2Size\t%d\n", wh.data_subchunk.subchunk2_size);
}