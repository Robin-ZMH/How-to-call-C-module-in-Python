from array import array
import sample

print(sample.multiply(4, 6))

print(sample.divide(9, 2))

print(f"new_arg={sample.pointer(10)}")

res = sample.mod(9, 2)
print(f'quotient={res[0]}, remainder={res[1]}')

li = [i for i in range(15)]
li = array('i', li)
print(sample.avg(li))

print('===========test==========')
print(sample.test(101))