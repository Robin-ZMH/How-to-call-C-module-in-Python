import python_test, cython_test, ctypesAPI, sample, time, originalPy


def cal_time(func):
	def wrapper(*args, **kwargs):
		start = time.time()
		res = func(*args, **kwargs)
		end = time.time()
		print(f'time span={end-start}s, res={res}')
		return end-start
	return wrapper


test_python = cal_time(originalPy.test)
test_cython = cal_time(python_test.test)
test_cython_plus = cal_time(cython_test.test)
test_ctypes = cal_time(ctypesAPI.test)
test_sample = cal_time(sample.test)

time0 = test_python(1000000)
time1 = test_cython(1000000)
time2 = test_cython_plus(1000000)
time3 = test_ctypes(1000000)
time4 = test_sample(1000000)

print(f'Cython is {int(time0 / time1)}x faster than Python')
print(f'Cython_plus is {int(time0 / time2)}x faster than Python')
print(f'Ctypes is {int(time0 / time3)}x faster than Python')
print(f'C is {int(time0 / time4)}x faster than Python')