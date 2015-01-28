// Author: Karl Stratos (karlstratos@gmail.com)
//
// Code for scaling and decomposing matrices.

#ifndef DECOMPOSE_H
#define DECOMPOSE_H

#include <Eigen/Dense>

#include "sparsesvd.h"

class Decomposer {
public:
    // Initializes empty.
    Decomposer() { }

    // Initializes with a dimension.
    Decomposer(size_t dim) : dim_(dim) { }

    ~Decomposer() { }

    // Decomposes a matrix with scaling.
    void Decompose(unordered_map<size_t, unordered_map<size_t, double> >
		   *joint_values,
		   const unordered_map<size_t, double> &values1,
		   const unordered_map<size_t, double> &values2);

    // Loads a matrix and scaling values from files and performs decomposition.
    void Decompose(const string &joint_values_path, const string &values1_path,
		   const string &values2_path);

    // Computes values from samples and performs decomposition.
    void Decompose(const vector<unordered_map<size_t, double> > &samples1,
		   const vector<unordered_map<size_t, double> > &samples2);

    // Sets the number of samples.
    void set_num_samples(size_t num_samples) { num_samples_ = num_samples; }

    // Sets a target dimension.
    void set_dim(size_t dim) { dim_ = dim; }

    // Sets the scaling method.
    void set_scaling_method(string scaling_method) {
	scaling_method_ = scaling_method;
    }

    // Sets a smoothing value.
    void set_smooth_value(size_t smooth_value) { smooth_value_ = smooth_value; }

    // Returns a matrix of scaled left singular vectors (as rows).
    Eigen::MatrixXd *left_matrix() { return &left_matrix_; }

    // Returns a matrix of scaled right singular vectors (as rows).
    Eigen::MatrixXd *right_matrix() { return &right_matrix_; }

    // Returns singular values.
    Eigen::VectorXd *singular_values() { return &singular_values_; }

    // Returns the number of samples.
    size_t num_samples() { return num_samples_; }

    // Returns the target dimension.
    size_t dim() { return dim_; }

    // Returns the actually computed SVD rank (might be smaller than the target
    // dimension if rank(matrix) < target dimension).
    size_t rank() { return rank_; }

    // Returns the scaling method.
    string scaling_method() { return scaling_method_; }

    // Returns the smoothing value.
    size_t smooth_value() { return smooth_value_; }

private:
    // Loads scaling values from a file.
    void LoadScalingValues(const string &scaling_values_path,
			   unordered_map<size_t, double> *scaling_values);

    // Scales a joint value by individual values.
    double ScaleJointValue(double joint_value, double value1, double value2);

    // Extracts scaled singular vectors from an SVD solver.
    void ExtractFromSVD(SparseSVDSolver *svd_solver,
			const unordered_map<size_t, double> &values1,
			const unordered_map<size_t, double> &values2);

    // Matrix of scaled left singular vectors (as rows).
    Eigen::MatrixXd left_matrix_;

    // Matrix of scaled right singular vectors (as rows).
    Eigen::MatrixXd right_matrix_;

    // Singular values.
    Eigen::VectorXd singular_values_;

    // Number of samples.
    size_t num_samples_ = 0;

    // Target dimension.
    size_t dim_ = 0;

    // Actually computed SVD rank (might be smaller than the target dimension
    // if rank(matrix) < target dimension).
    size_t rank_ = 0;

    // Scaling method.
    string scaling_method_ = "cca";

    // Smoothing value.
    size_t smooth_value_ = 5;
};

#endif  // DECOMPOSE_H
