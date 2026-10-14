This is a simple text generator based on a training file, a so called small language model (SLM). 

Instructions:
The code in src can be compiled using the Makefile. Type make into the terminal when inside the directory. To run, the format is ./slm -a <alpha> <k> <"filename.txt"> <length> or ./slm <k> <"filename.txt"> <length> for alpha = 0. alpha is the smoothing parameter, k is the length of the so called k-gram samples from the training text. "filename.txt" is where you enter your training txt file, and length is the length of the generated text.
