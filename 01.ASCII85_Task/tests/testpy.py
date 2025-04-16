''' Ilya Pavlov st129535@student.spbu.ru
	01.ASCII85_Task
'''

import subprocess
import random
import string
from base64 import a85encode, a85decode

def encoder(code):
    return(a85encode(code.encode()).decode())

def decoder(code):
    return(a85decode(code.encode()).decode())
    
def py_test(cpp_in, py_in):
    py_out = decoder(subprocess.run(["./run.sh","-e"], input = cpp_in.encode(), stdout = subprocess.PIPE).stdout.decode()[24:-3])
    cpp_out = subprocess.run(["./run.sh","-d"], input = (encoder(py_in)+"~>").encode(), stdout = subprocess.PIPE).stdout.decode()[24:-1]
#    print(cpp_in, py_out, "\n", py_in, cpp_out)
    return (py_in == cpp_out) and (cpp_in == py_out)

def randstring(N):
    if N == 0:
        N = random.randint(5,15);
    cpp_in = ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase + string.digits, k=N))
    py_in = ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase + string.digits, k=N))
    return cpp_in, py_in
    
def test1():
    print("Testing random string 5-15 char length")
    assert py_test(*randstring(0)) == True
    
def test2():
    print("Testing random string 10 char length")
    assert py_test(*randstring(10)) == True
def test3():
    print("Testing random string 1024 char length")
    assert py_test(*randstring(1024)) == True



    

