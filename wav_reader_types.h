//
// Created by franciscohanna92 on 08/09/18.
//

#ifndef WAV_READER_WAV_READER_TYPES_H
#define WAV_READER_WAV_READER_TYPES_H

struct riff_header {
    char chunk_id[5];       // Contains the letters "RIFF" in ASCII form
    int chunk_size;         // This is the size of the entire file in bytes minus 8 bytes (ChunkID and ChunkSize not included).
    char format[5];         // Contains the letters "WAVE"
};

struct fmt_subchunk {
    char subchunk1_id[5];   // Contains the letters "fmt "
    int subchunk1_size;     // 16 or 18 for PCM.  This is the size of the rest of the Subchunk which follows this number.
    int audio_format;       // PCM = 1 (i.e. Linear quantization) Values other than 1 indicate some form of compression.
    int num_channels;       // Mono = 1, Stereo = 2, etc.
    int sample_rate;        // 8000, 44100, etc.
    int byte_rate;          // == SampleRate * NumChannels * BitsPerSample/8
    int block_align;        // == NumChannels * BitsPerSample/8. The number of bytes for one sample including all channels
    int bits_per_sample;    // 8 bits = 8, 16 bits = 16, etc.
};

struct data_subchunk {
    char subchunk2_id[5];   // Contains the letters "data"
    int subchunk2_size;     // == NumSamples * NumChannels * BitsPerSample/8. This is the number of bytes in the data.
};

struct wav_header {
    struct riff_header riff_header;
    struct fmt_subchunk fmt_subchunk;
    struct data_subchunk data_subchunk;
};

#endif //WAV_READER_WAV_READER_TYPES_H
