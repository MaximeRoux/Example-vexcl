void test_multi_vector(){
	size_t size = 10;
	std::vector<float> a(size);
  
	using type = vex::multivector<double, 3>;
  
	type data[5];
	data[2].resize(size);
	data[2](0) = 10;
	data[2](1) = 10;
	data[2](2) = 10;
  
	vex::copy(data[2](0), a); //copy device to host
}
