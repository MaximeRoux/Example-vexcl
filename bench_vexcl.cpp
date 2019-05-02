void bench() {

	std::vector<float> a(n), b(n), c(n), d(n); // Host vector.
  
	vex::Context ctx(vex::Filter::GPU); //Contexte
	vex::vector<float> a_d(n), b_d(n), c_d(n), res_d(n);  // Device vector.
	
  for (size_t i = 0; i < n; i++)
	{
		a[i] = (i*1.0f + 4.)*0.5;
		b[i] = (i*1.0f + 5.)*0.5;
		c[i] = (i*1.0f + 6.)*0.5;
	}

	vex::copy(a, a_d);    // Copy data from host to device.
	vex::copy(b, b_d);    // Copy data from host to device.
	vex::copy(c, c_d);    // Copy data from host to device.
  
	res_d = a_d + b_d - 2.4f * c_d; //Compute on device
	
	vex::copy(res_d, d);// Copy data from device to host.
  
}
