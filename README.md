# WAV header reader
A simple C program to read WAV files header

## How to use
Clone the repository. Build the project by `cd` into de `cmake-build-debug` folder and run `make`.
Execute the `wav_reader` binary, passing as a argument a path to a WAV file. The content of the header will be printed in the standard output.

## How it works
Following the [specification for the WAV header format](http://soundfile.sapp.org/doc/WaveFormat/), the task of reading this part of a WAV file is trivial.
It's only matter of following the bytes per section. Checkout the methods in `lib/wav_reader_methods.c`. They're pretty much self explainable.
![The Cannonical WAV file format](http://soundfile.sapp.org/doc/WaveFormat/wav-sound-format.gif)
