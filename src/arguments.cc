// Author: Karl Stratos (stratos@cs.columbia.edu)

#include "arguments.h"

void CountArgumentProcessor::ParseArguments(int argc, char* argv[]) {
    bool display_options_and_quit = false;
    for (int i = 1; i < argc; ++i) {
	string arg = (string) argv[i];
	if (arg == "--corpus") {
	    corpus_path_ = argv[++i];
	} else if (arg == "--output") {
	    output_directory_ = argv[++i];
	} else if (arg == "--rare") {
	    rare_cutoff_ = stol(argv[++i]);
	} else if (arg == "--sentences") {
	    sentence_per_line_ = true;
	} else if (arg == "--window") {
	    window_size_ = stol(argv[++i]);
	} else if (arg == "--context") {
	    context_definition_ = argv[++i];
	} else if (arg == "--help" || arg == "-h"){
	    display_options_and_quit = true;
	} else {
	    cerr << "Invalid argument \"" << arg << "\": run the command with "
		 << "-h or --help to see possible arguments." << endl;
	    exit(-1);
	}
    }

    if (display_options_and_quit || argc == 1) {
	cout << "--corpus [-]:       \t"
	     << "path to a text file" << endl;

	cout << "--output [-]:       \t"
	     << "path to an output directory" << endl;

	cout << "--rare [" << rare_cutoff_ << "]:     \t"
	     << "rare word count threshold" << endl;

	cout << "--sentences:        \t"
	     << "have a sentence per line in the corpus" << endl;

	cout << "--window [" << window_size_ << "]:    \t"
	     << "size of the sliding window" << endl;

	cout << "--context [" << context_definition_ << "]: \t"
	     << "context definition: bag, list, baglist"  << endl;

	exit(0);
    }
}

void ArgumentProcessor::ParseArguments(int argc, char* argv[]) {
    bool display_options_and_quit = false;
    for (int i = 1; i < argc; ++i) {
	string arg = (string) argv[i];
	if (arg == "--corpus") {
	    corpus_path_ = argv[++i];
	} else if (arg == "--output") {
	    output_directory_ = argv[++i];
	} else if (arg == "--force" || arg == "-f") {
	    from_scratch_ = true;
	} else if (arg == "--rare") {
	    rare_cutoff_ = stol(argv[++i]);
	} else if (arg == "--sentences") {
	    sentence_per_line_ = true;
	} else if (arg == "--window") {
	    window_size_ = stol(argv[++i]);
	} else if (arg == "--context") {
	    context_definition_ = argv[++i];
	} else if (arg == "--dim") {
	    dim_ = stol(argv[++i]);
	} else if (arg == "--transform") {
	    transformation_method_ = argv[++i];
	} else if (arg == "--scale") {
	    scaling_method_ = argv[++i];
	} else if (arg == "--help" || arg == "-h"){
	    display_options_and_quit = true;
	} else {
	    cerr << "Invalid argument \"" << arg << "\": run the command with "
		 << "-h or --help to see possible arguments." << endl;
	    exit(-1);
	}
    }

    if (display_options_and_quit || argc == 1) {
	cout << "--corpus [-]:       \t"
	     << "path to a text file" << endl;

	cout << "--output [-]:       \t"
	     << "path to an output directory" << endl;

	cout << "--force, -f:         \t"
	     << "forcefully recompute from scratch" << endl;

	cout << "--rare [" << rare_cutoff_ << "]:     \t"
	     << "rare word count threshold" << endl;

	cout << "--sentences:        \t"
	     << "have a sentence per line in the corpus" << endl;

	cout << "--window [" << window_size_ << "]:    \t"
	     << "size of the sliding window" << endl;

	cout << "--context [" << context_definition_ << "]: \t"
	     << "context definition: bag, list, baglist"  << endl;

	cout << "--dim [" << dim_ << "]:        \t"
	     << "dimensionality of word vectors" << endl;

	cout << "--transform [" << transformation_method_ << "]: \t"
	     << "data transform: raw, sqrt, two-thirds, log"
	     << endl;

	cout << "--scale [" << scaling_method_ << "]:    \t"
	     << "data scaling: raw, cca, reg, ppmi" << endl;

	cout << "--help, -h:           \t"
	     << "show options and quit" << endl;

	exit(0);
    }
}
