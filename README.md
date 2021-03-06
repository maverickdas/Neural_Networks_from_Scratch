# Neural Networks from Scratch
Implementing an Artificial Neural Network from scratch using C++

There are two implementations listed here:
1) A [basic_ann](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/master/basic_ann.cpp) without using any libraries, just raw C++. The [main](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/55c7b0e9a8a3571a726ab744151ba351a4840dfb/basic_ann.cpp#L191) function here is to train the network to act as a 3-input XOR operator.

2) A vectorized implementation of an ANN (include [this header](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/master/AF_ANN.hpp)) using the [ArrayFire](http://arrayfire.org/docs/index.htm) library that allows the use of an unified source-code to compile programs for CPU, CUDA, as well as OpenCL. Some features that allow for smooth experimentation:
    - Ability to add custom activation functions using the [`Layer::setNewActivation`](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/1255ffddde497e32aaf9e673e8ea6e3493b8a368/Layer.hpp#L65) function, as shown [here](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/1255ffddde497e32aaf9e673e8ea6e3493b8a368/custom_activation.cpp#L32). 
    - Decaying learning rate across epochs as shown [here](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/56bc2fee8341ac7790ad70fb0a14c92d987f17fd/test_XOR.cpp#L60), by defining a custom [`calc_LRdecay`](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/56bc2fee8341ac7790ad70fb0a14c92d987f17fd/test_XOR.cpp#L16) function.

## Implementations ##
- Implementation of [XOR gate](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/master/test_XOR.cpp) with [loss-values](https://github.com/codebuddha/Neural_Networks_from_Scratch/blob/master/test_XOR_training.txt).
- Using the ANN to classify NLTK Movie-Reviews as postive or negative, by using TFIDF transform for feature description. [repo](https://github.com/DarkStar1997/Movie-Review-Sentiment-Analysis)
