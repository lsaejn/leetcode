import numpy as np

data=np.genfromtxt("test.txt",delimiter='\t',dtype=str)
print(type(data))#ndarray
print(data)
#print(help(data))

vector=np.array([5,10,15,20])
matrix=np.array([[1,2,3],[3,2,1],[0,4,5]])
print(vector,'\n',matrix)
print(vector.shape)
print(matrix.shape)

vector=np.array([5.0,10,15,20])
print(vector)

matrix=np.array([[1,2,3],
                 [3,2,1],
                 [0,4,5]])
print(matrix[1])
print(matrix[:,1])
print(matrix[0:3,0:3])#行范围[0,3)

from numpy import pi
print(np.linspace( 0, 2*pi, 100 ))