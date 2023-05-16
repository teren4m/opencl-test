// TestCMake.cpp : Defines the entry point for the application.
//

#include "TestCMake.h"
#ifdef __APPLE__
#include <OpenCL/cl.hpp>
#else
#include <CL/cl.hpp>
#endif

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#define LENGTH (1024)
#define TOL (0.001)

// pick up device type from compiler command line or from the default type
#ifndef DEVICE
#define DEVICE CL_DEVICE_TYPE_DEFAULT
#endif

float gen_random() { return rand() / (float)RAND_MAX; }

std::string load_program(std::string input) {
	std::ifstream stream(input.c_str());
	if (!stream.is_open()) {
		std::cout << "Cannot open file: " << input << std::endl;
		exit(1);
	}
	return std::string(std::istreambuf_iterator<char>(stream),
		(std::istreambuf_iterator<char>()));
}

std::string from_lib() {
	return "From lib";
}

//int main() {
//
//	std::cout << "Len: " << LENGTH << std::endl;
//	// declare host containers
//	std::vector<float> h_a(LENGTH);
//	std::vector<float> h_b(LENGTH);
//	std::vector<float> h_c(LENGTH);
//
//	// declare device containers
//	cl::Buffer d_a;
//	cl::Buffer d_b;
//	cl::Buffer d_c;
//
//	// fill host containers with random numbers
//	std::generate(h_a.begin(), h_a.end(), gen_random);
//	std::generate(h_b.begin(), h_b.end(), gen_random);
//
//	// create a context
//	cl::Device device = cl::Device::getDefault();
//	unsigned int device_name = 1;
//	std::string device_vendor;
//	cl::Context context(device);
//	cl_int err = device.getInfo(CL_DEVICE_PARENT_DEVICE, &device_vendor);
//	std::cout << device_name << std::endl;
//	std::cout << device_vendor << std::endl;
//
//	// load in kernel source, creating a program object for the context
//	cl::Program program(context, load_program("cl/vadd.cl"), true);
//
//
//	// get the command queue
//	cl::CommandQueue queue(context, device);
//
//	// create the kernel functor
//	auto vadd =
//		cl::make_kernel<cl::Buffer, cl::Buffer, cl::Buffer, int>(program, "vadd");
//
//	// copy data to device
//	d_a = cl::Buffer(begin(h_a), end(h_a), true);
//	d_b = cl::Buffer(begin(h_b), end(h_b), true);
//
//	// allocate results container
//	d_c = cl::Buffer(context, CL_MEM_WRITE_ONLY, sizeof(float) * LENGTH);
//
//	// run calculations
//	vadd(cl::EnqueueArgs(queue, cl::NDRange(LENGTH)), d_a, d_b, d_c, LENGTH);
//
//	queue.finish();
//
//	cl::copy(d_c, begin(h_c), end(h_c));
//
//	// test the results
//	int correct = 0;
//	float tmp;
//	for (int i = 0; i < LENGTH; i++) {
//		tmp = h_a[i] + h_b[i];       // expected value for d_c[i]
//		tmp -= h_c[i];               // compute errors
//		if (tmp * tmp < TOL * TOL) { // correct if square deviation is less
//			correct++;                 //  than tolerance squared
//		}
//		else {
//			//printf(" tmp %f h_a %f h_b %f  h_c %f \n", tmp, h_a[i], h_b[i], h_c[i]);
//		}
//	}
//
//	printf("vector add to find C = A+B:  %d out of %d results were correct.\n",
//		correct, LENGTH);
//}