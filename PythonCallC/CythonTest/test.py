import cython_test
import c_test
import time


def cal_time(func):
	def wrapper(*args, **kwargs):
		start = time.time()
		res = func(*args, **kwargs)
		end = time.time()
		print(f'{func.__name__}={end-start}s')
		return end-start
	return wrapper

test1 = cal_time(cython_test.test)
test2 = cal_time(c_test.test)

time1 = test1(10000000)
time2 = test2(10000000)
print(f'C is {int(time1 / time2)}x faster than Python')