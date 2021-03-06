// Author: Karl Stratos (stratos@cs.columbia.edu)

#include "src/arguments.h"
#include "src/wordrep.h"

int main (int argc, char* argv[]) {
    ArgumentProcessor argparser;
    argparser.ParseArguments(argc, argv);

    // Initialize a WordRep object.
    WordRep wordrep(argparser.output_directory());
    wordrep.set_rare_cutoff(argparser.rare_cutoff());
    wordrep.set_sentence_per_line(argparser.sentence_per_line());
    wordrep.set_window_size(argparser.window_size());
    wordrep.set_context_definition(argparser.context_definition());
    wordrep.set_dim(argparser.dim());
    wordrep.set_transformation_method(argparser.transformation_method());
    wordrep.set_scaling_method(argparser.scaling_method());
    wordrep.set_num_context_hashed(argparser.num_context_hashed());
    wordrep.set_pseudocount(argparser.pseudocount());
    wordrep.set_context_smoothing_exponent(
	argparser.context_smoothing_exponent());
    wordrep.set_singular_value_exponent(argparser.singular_value_exponent());
    wordrep.set_verbose(argparser.verbose());

    // If given a corpus, extract statistics from it.
    if (!argparser.corpus_path().empty()) {
	if (argparser.from_scratch()) { wordrep.ResetOutputDirectory(); }
	wordrep.ExtractStatistics(argparser.corpus_path());
    }

    // Induce word representations from cached statistics.
    wordrep.InduceLexicalRepresentations();
}
